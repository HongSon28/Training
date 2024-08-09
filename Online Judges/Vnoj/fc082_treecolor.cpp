#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int c[N+5],res[N+5];
vector<vector<int>>adj(N+5);
set<int>s[N+5];
void dfs(int u,int par) {
	s[u].insert(c[u]);
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		if (s[u].size()<s[v].size()) swap(s[u],s[v]);
		for (auto i:s[v]) s[u].insert(i);
		s[v].clear();
	}
	res[u]=s[u].size();
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) cin>>c[i];
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<res[i]<<'\n';
}