#include<bits/stdc++.h>
using namespace std;
const int N=800;
int n,m;
vector<int>adj[N+5],rev[N+5];
bool vis[N+5];
int cmp[N+5],deg[N+5];
vector<int>v1,v2;
vector<vector<int>>comp;
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
	for (int i=1;i<=n;i++) {
		if (!vis[i]) dfs1(i);
	}
	memset(vis,false,sizeof(vis));
	reverse(v1.begin(),v1.end());
	for (auto u:v1) {
		if (!vis[u]) {
			dfs2(u);
			comp.push_back(v2);
			for (auto v:v2) {
				cmp[v]=comp.size();
			}
			v2.clear();
		}
	}
	for (int u=1;u<=n;u++) {
		for (auto v:adj[u]) {
			if (cmp[u]!=cmp[v]) deg[cmp[v]]++;
		}
	}
	int res=0;	
	for (int i=1;i<=comp.size();i++) res+=(deg[i]==0);
	cout<<res;
}