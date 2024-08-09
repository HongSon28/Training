#include<bits/stdc++.h>
using namespace std;
const int N=7e4,LG=__lg(N+5);
int n,q;
vector<vector<int>>adj(N+5);
int h[N+5],up[N+5][LG+5];
void dfs(int u) {
	for (auto v:adj[u]) {
		if (v==up[u][0]) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		for (int i=1;i<=LG;i++) up[v][i]=up[up[v][i-1]][i-1];
		dfs(v);
	}
}
int lca(int u,int v) {
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int i=0;(1<<i)<=k;i++) {
			if (k>>i&1) {
				u=up[u][i];
			}
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
int rmq[N+5][LG+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1);
    for (int i=1;i<=n;i++) rmq[i][0]=i;
    for (int j=1;j<=LG;j++) {
    	for (int i=1;i+(1<<j-1)<=n;i++) {
    		rmq[i][j]=lca(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
    	}
    }
    while (q--) {
    	int u,v;
    	cin>>u>>v;
    	int k=__lg(v-u+1);
    	cout<<lca(rmq[u][k],rmq[v-(1<<k)+1][k])<<'\n';
    }
}