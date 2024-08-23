#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=18;
int n,m;
vector<int>adj[N+5];
int h[N+5],up[N+5][LG+5],d[N+5];
void dfs(int u,int par) {
	h[u]=h[par]+1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		up[v][0]=u;
		for (int i=1;i<=LG;i++) up[v][i]=up[up[v][i-1]][i-1];
		dfs(v,u);
	}
}
int lca(int u,int v) {
	if (h[u]<h[v]) swap(u,v);
	int k=h[u]-h[v];
	for (int i=0;i<=LG;i++) {
		if (k>>i&1) u=up[u][i];
	}
	if (u==v) return u;
	k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
void calc(int u,int par) {
	for (auto v:adj[u]) {
		if (v==par) continue;
		calc(v,u);
	}
	d[par]+=d[u];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,0);
    while (m--) {
    	int u,v;
    	cin>>u>>v;
    	int k=lca(u,v);
    	d[u]++;
    	d[v]++;
    	d[up[k][0]]--;
    	d[k]--;
    }
    calc(1,0);
    for (int i=1;i<=n;i++) cout<<d[i]<<' ';
}