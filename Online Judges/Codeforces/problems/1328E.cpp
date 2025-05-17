#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=18;
int n,q;
vector<int>adj[N+5];
int d[N+5];
int up[N+5][LG+5];
void dfs(int u,int par) {
	d[u]=d[par]+1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		up[v][0]=u;
		for (int i=1;i<=LG;i++) up[v][i]=up[up[v][i-1]][i-1];
		dfs(v,u);
	}
}
int lca(int u,int v) {
	if (d[u]!=d[v]) {
		if (d[u]<d[v]) swap(u,v);
		int k=d[u]-d[v];
		for (int i=0;i<=LG;i++) {
			if (k>>i&1) u=up[u][i];
		}
	}
	if (u==v) return u;
	for (int i=LG;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
void solve() {
	vector<int>vc;
	int k;
	cin>>k;
	int deep=-1;
	for (int i=1;i<=k;i++) {
		int u;
		cin>>u;
		if (u!=1) vc.push_back(up[u][0]);
		else vc.push_back(u);
	}
	for (auto u:vc) {
		if (deep==-1||d[deep]<d[u]) deep=u;
	}
	for (auto u:vc) {
		if (lca(u,deep)!=u) {
			cout<<"NO"<<'\n';
			return;
		}
	}
	cout<<"YES"<<'\n';
}
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
    dfs(1,0);
    while (q--) solve();
}