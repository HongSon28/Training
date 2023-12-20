#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int dp[N+5],mx[N+5],h[N+5],up[N+5][LG+5];
int t,n;
vector<vector<int>>adj(N+5);
void dfs_lca(int u) {
	mx[u]=h[u];
	for (auto v:adj[u]) {
		h[v]=h[u]+1;
		up[v][0]=u;
		for (int k=1;k<=LG;k++) up[v][k]=up[up[v][k-1]][k-1];
		dfs_lca(v);
		mx[u]=max(mx[u],mx[v]);
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
stack<int>cur;
void solve(int u) {
	vector<pair<int,int>>vc;
	for (auto v:adj[u]) {
		vc.push_back({mx[v],v});
	}
	sort(vc.rbegin(),vc.rend());
	for (auto [w,v]:vc) {
		solve(v);
	}
	cout<<u;
	if (!cur.empty()) {
		int t=lca(cur.top(),u);
		if (t!=u&&t!=cur.top()) {
			cur.pop();
		} else cur.push(u);
	} else cur.push(u);
	cout<<' '<<cur.size()<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		while (!cur.empty()) cur.pop();
		adj.clear();
		adj.resize(n+1);
		for (int i=2;i<=n;i++) {
			int p;
			cin>>p;
			adj[p].push_back(i);
		}
		dfs_lca(1);
		solve(1);
		cout<<(n-cur.size())/2<<'\n';
	}
}