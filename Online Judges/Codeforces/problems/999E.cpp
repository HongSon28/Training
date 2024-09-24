#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,m,s,res;
vector<int>adj[N+5],rev_adj[N+5],comp_adj[N+5];
int comp[N+5],indeg[N+5];
bool vis[N+5];
vector<int>order,vcomp,root;
void dfs1(int u) {
	vis[u]=true;
	for (auto v:adj[u]) 
		if (!vis[v]) dfs1(v);
	order.push_back(u);
}
void dfs2(int u) {
	vis[u]=true;
	for (auto v:rev_adj[u]) 
		if (!vis[v]) dfs2(v);
	vcomp.push_back(u);
}
void dfs3(int u) {
	vis[u]=true;
	for (auto v:comp_adj[u]) 
		if (!vis[v]) dfs3(v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>s;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		rev_adj[v].push_back(u);
	} 
	for (int i=1;i<=n;i++) {
		if (!vis[i]) dfs1(i);
	}
	memset(vis,false,sizeof(vis));
	reverse(order.begin(),order.end());
	for (auto u:order) {
		if (vis[u]) continue;
		vcomp.clear();
		dfs2(u);
		sort(vcomp.begin(),vcomp.end());
		for (auto v:vcomp) comp[v]=vcomp[0];
		root.push_back(vcomp[0]);
	}
	for (int u=1;u<=n;u++) {
		for (auto v:adj[u])
			if (comp[u]!=comp[v]) { 
				comp_adj[comp[u]].push_back(comp[v]);
				indeg[comp[v]]++;
			}
	}
	memset(vis,false,sizeof(vis));
	dfs3(comp[s]);
	for (auto u:root) {
		res+=(!vis[u]&&!indeg[u]);
	}
	cout<<res;
}