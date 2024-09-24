#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
bool vis[N+5];
vector<int>adj[N+5],rev[N+5];
vector<int>v1,v2;
vector<vector<int>>comps;
int comp[N+5];
void dfs1(int u) {
	vis[u]=true;
	for (auto v:adj[u]) {
		if (!vis[v]) dfs1(v);
	}
	v1.push_back(u);
}
void dfs2(int u) {
	vis[u]=true;
	for (auto v:rev[u]) {
		if (!vis[v]) dfs2(v);
	}
	v2.push_back(u);
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	for (int i=1;i<=n;i++) 
		if (!vis[i]) dfs1(i);
	memset(vis,false,sizeof(vis));
	reverse(v1.begin(),v1.end());
	for (auto u:v1) {
		if (vis[u]) continue;
		v2.clear();
		dfs2(u);
		comps.push_back(v2);
	}
	for (int i=0;i<(int)comps.size();i++) {
		for (auto u:comps[i]) comp[u]=i+1;
	}
	cout<<comps.size()<<'\n';
	for (int i=1;i<=n;i++) cout<<comp[i]<<' ';
}