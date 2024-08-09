#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int n;
vector<vector<pair<int,int>>>adj(N+5);
long long c1[N+5],c2[N+5],res;
int par[N+5];
long long up[N+5][LG+5],h[N+5],d[N+5];
void dfs_lca(int u,int p) {
	for (auto [v,id]:adj[u]) {
		if (v==p) continue;
		par[v]=id;
		up[v][0]=u;
		h[v]=h[u]+1;
		for (int k=1;k<=LG;k++) up[v][k]=up[up[v][k-1]][k-1];
		dfs_lca(v,u);
	}
}
int lca(int u,int v) {
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int i=0;(1<<i)<=k;i++) {
			if (k>>i&1) u=up[u][i];
		}
	}
	if (u==v) return u;
	int k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
void dfs(int u,int p) {
	for (auto [v,id]:adj[u]) {
		if (v==p) continue;
		dfs(v,u);
		d[u]+=d[v];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v>>c1[i]>>c2[i];
    	adj[u].push_back({v,i});
    	adj[v].push_back({u,i});
    }
    dfs_lca(1,0);
    for (int i=2;i<=n;i++) {
    	int u=lca(i,i-1);
    	d[i]++;
    	d[i-1]++;
    	d[u]-=2;
    }
    dfs(1,0);
    for (int i=2;i<=n;i++) {
    	int id=par[i];
    	res+=min(c2[id],c1[id]*d[i]);
    }
    cout<<res;
}