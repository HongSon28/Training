#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int n,m;
vector<vector<int>>adj(N+5);
int up[N+5][LG+5],h[N+5],d[N+5],res;
void dfs(int u) {
	for (auto v:adj[u]) {
		if (v==up[u][0]) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		for (int k=1;k<=LG;k++) up[v][k]=up[up[v][k-1]][k-1];
		dfs(v);
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
void dfs2(int u) {
	for (auto v:adj[u]) {
		if (v==up[u][0]) continue;
		dfs2(v);
		d[u]+=d[v];
	}
	if (d[u]==0) res++;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1);
    cin>>m;
    while (m--) {
    	int u,v;
    	cin>>u>>v;
    	int k=lca(u,v);
    	d[u]++;
    	d[v]++;
    	d[k]-=2;
    }
    dfs2(1);
    cout<<res-1;
}
