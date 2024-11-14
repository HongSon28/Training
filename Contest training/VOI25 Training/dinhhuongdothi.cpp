#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
vector<pair<int,int>>adj[N+5];
pair<int,int>edge[N+5];
long long deg[N+5],res;
vector<int>v;
bool used[N+5];
void dfs(int u) {
	for (auto [v,id]:adj[u]) {
		if (used[id]) continue;
		used[id]=true;
		edge[id]={u,v};
		dfs(v);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
		deg[u]++,deg[v]++;
	}
	for (int i=1;i<=n;i++) {
		if (deg[i]%2==1) v.push_back(i);
		res+=(deg[i]/2)*((deg[i]+1)/2);
	}
	int cur=m;
	for (int i=0;i<(int)v.size();i+=2) {
		cur++;
		adj[v[i]].push_back({v[i+1],cur});
		adj[v[i+1]].push_back({v[i],cur});
		deg[v[i]]++,deg[v[i+1]]++;
	}
	for (int i=1;i<=n;i++) dfs(i);
	cout<<res<<'\n';
	for (int i=1;i<=m;i++) cout<<edge[i].first<<' '<<edge[i].second<<'\n';
}