#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k,x[N+5],inf=1e9;
vector<vector<int>>adj(N+5);
int dist[N+5],h[N+5],opt[N+5];
vector<int>res;
bool vis[N+5];
void bfs() {
	for (int i=1;i<=n;i++) dist[i]=inf;
	queue<int>q;
	for (int i=1;i<=k;i++) {
		q.push(x[i]);
		dist[x[i]]=0;
	}
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (dist[v]>dist[u]+1) {
				q.push(v);
				dist[v]=dist[u]+1;
			}
		}
	}
}
void dfs1(int u,int par,int mx,int st) {
	if (h[u]+dist[u]>mx) {
		mx=h[u]+dist[u];
		st=u;
	}
	opt[u]=st;
	for (auto v:adj[u]) {
		if (v==par) continue;
		h[v]=h[u]+1;
		dfs1(v,u,mx,st);
	}
} 
bool comp(int a,int b) {
	return h[a]>h[b];
}
void dfs2(int u) {
	vis[u]=true;
	for (auto v:adj[u]) {
		if (!vis[v]&&dist[v]+1==dist[u]) dfs2(v);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("SHEEP.INP","r",stdin);
	freopen("SHEEP.OUT","w",stdout);
	cin>>n>>k;
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=1;i<=k;i++) cin>>x[i];
	bfs();
	dfs1(1,0,-1,0);
	sort(x+1,x+1+k,comp);
	for (int i=1;i<=k;i++) {
		if (!vis[x[i]]) {
			res.push_back(opt[x[i]]);
			dfs2(opt[x[i]]);
		}
	}
	cout<<res.size()<<'\n';
	for (auto i:res) cout<<i<<' ';
}