#include<bits/stdc++.h>
using namespace std;
const int N=5e4,LG=__lg(N+5);
int n,k,res;
vector<vector<int>>adj(N+5);
int d[N+5];
int h[N+5],up[N+5][LG+5];
void dfs_lca(int u) {
	for (auto v:adj[u]) {
		if (v==up[u][0]) continue;
		up[v][0]=u;
		h[v]=h[u]+1;
		for (int k=1;k<=LG;k++) up[v][k]=up[up[v][k-1]][k-1];
		dfs_lca(v);
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
	for (int j=k;j>=0;j--) {
		if (up[u][j]!=up[v][j]) {
			u=up[u][j];
			v=up[v][j];
		}
	}
	return up[u][0];
}
void dfs(int u) {
	for (auto v:adj[u]) {
		if (v==up[u][0]) continue;
		dfs(v);
		d[u]+=d[v];
	}
	res=max(res,d[u]);
}
int main() {
	//freopen("pathcnt.inp","r",stdin);
	//freopen("pathcnt.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    dfs_lca(1);
    while (k--) {
    	int u,v,t;
    	cin>>u>>v;
    	t=lca(u,v);
    	d[u]++;
    	d[v]++;
    	d[t]--;
    	d[up[t][0]]--;
    }
    dfs(1);
    cout<<res;
}