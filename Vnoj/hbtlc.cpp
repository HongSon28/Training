#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
int n,m;
vector<vector<int>>adj;
int h[N+5],up[N+5][LG+5],root=1;
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
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    while (cin>>n) {
    	if (n==0) break;
    	root=1;
    	adj.clear();
    	adj.resize(n+1);
	    for (int i=1;i<n;i++) {
	    	int u,v;
	    	cin>>u>>v;
	    	adj[u].push_back(v);
	    	adj[v].push_back(u);
	    }
	    dfs(1);
	    cin>>m;
	    while (m--) {
	    	char c;
	    	cin>>c;
	    	if (c=='!') {
	    		cin>>root;
	    	} else {
	    		int u,v,res;
	    		cin>>u>>v;
	    		int lu=lca(u,root),lv=lca(v,root);
	    		if (h[lu]>=h[lv]) res=lu;
	    		else res=lv;
	    		int l=lca(u,v);
	    		if (h[res]<h[l]) res=l;
	    		cout<<res<<'\n';
	    	}
	    }
    }
}
