#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,s;
vector<vector<pair<int,long long>>>adj(N+5),adj2(N+5);
bool deleted[N+5];
int low[N+5],num[N+5],label[N+5];
int timer;
stack<int>st;
void dfs(int u) {
	label[u]=u;
	num[u]=low[u]=++timer;
	st.push(u);
	for (auto [v,w]:adj[u]) {
		if (deleted[v]) continue;
		if (!num[v]) {
			dfs(v);
			low[u]=min(low[u],low[v]);
		} else low[u]=min(low[u],num[v]);
	}
	if (low[u]==num[u]) {
		scc++;
		int v;
		do{
			v=st.top();
			st.pop();
			deleted[v]=true;
			label[v]=u;
		} while (v!=u);
	}
}
long long calc(long long w) {
	int lo=1,hi=1e9;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		long long last=w-mid*(mid-1)/2
		if (last>0){
			lo=mid+1;
		} else hi=mid-1;
	}
}
int vis[N+5];
vector<int>revTopo;
void dfs_topo(int u) {
    vis[u]=1;
    for (auto v : adj2[u])
        if (!vis[v]) dfs_topo(v);
    revTopo.push_back(u);
    vis[u]=2;
}
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	cin>>s;
	dfs(s);
	for (int u=1;u<=n;u++) {
		for (auto [v,w]:adj[u]) {
			int x=label[u],y=label[v];
			if (x==y) val[x]+=calc(w);
			else adj2[x].push_back({v,w});
		}
	}
}