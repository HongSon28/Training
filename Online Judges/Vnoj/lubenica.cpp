#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
int n,q;
vector<vector<pair<int,int>>>adj(N+5);
int h[N+5],up[N+5][LG+5],mn[N+5][LG+5],mx[N+5][LG+5];
void dfs(int u,int par) {
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		mn[v][0]=mx[v][0]=w;
		for (int k=1;k<=LG;k++) {
			up[v][k]=up[up[v][k-1]][k-1];
			mn[v][k]=min(mn[v][k-1],mn[up[v][k-1]][k-1]);
			mx[v][k]=max(mx[v][k-1],mx[up[v][k-1]][k-1]);
		}
		dfs(v,u);
	}
}
pair<int,int> lca(int u,int v) {
	int resmax=0,resmin=1e9;
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int i=0;(1<<i)<=k;i++) {
			if (k>>i&1) {
				resmin=min(resmin,mn[u][i]);
				resmax=max(resmax,mx[u][i]);
				u=up[u][i];
			}
		}
	}
	if (u==v) return {resmax,resmin};
	int k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			resmin=min({resmin,mn[u][i],mn[v][i]});
			resmax=max({resmax,mx[u][i],mx[v][i]});
			u=up[u][i];
			v=up[v][i];
		}
	}
	resmin=min({resmin,mn[u][0],mn[v][0]});
	resmax=max({resmax,mx[u][0],mx[v][0]});
	return {resmax,resmin};
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dfs(1,0);
    cin>>q;
    while (q--) {
    	int u,v;
    	cin>>u>>v;
    	pair<int,int>res=lca(u,v);
    	cout<<res.second<<' '<<res.first<<'\n';
    }
}