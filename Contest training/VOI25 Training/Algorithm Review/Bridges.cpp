#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,m;
vector<vector<int>>adj,tree;
vector<pair<int,int>>bridge;
multiset<pair<int,int>>s;
vector<int>comp[N+5];
int root[N+5];
int low[N+5],num[N+5],vis[N+5],tim;
void dfs(int u,int par) {
	low[u]=num[u]=++tim;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (!num[v]) {
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if (num[v]==low[v]) {
				bridge.push_back({u,v});
				s.insert({u,v});
				s.insert({v,u});
			}
		} else low[u]=min(low[u],num[v]);
	}
}
void dfs1(int u,int cur) {
	vis[u]=true;
	root[u]=cur;
	comp[cur].push_back(u);
	for (auto v:adj[u]) {
		if (s.count({u,v})||vis[v]) continue;
		dfs1(v,cur);
	}
}
int f[N+5],g[N+5],res;
void dfs2(int u,int par) {
	int mx1=0,mx2=0;
	for (auto v:tree[u]) {
		if (v==par) continue;
		dfs2(v,u);
		g[u]=max(g[u],g[v]+1);
		mx2=max(mx2,g[v]+1);
		if (mx2>mx1) swap(mx1,mx2);
	}
	f[u]=mx1+mx2+1;
	res=max(res,f[u]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m;
    	adj.clear(),tree.clear(),bridge.clear(),s.clear();
    	adj.resize(n+1),tree.resize(n+1);
    	for (int i=1;i<=m;i++) {
    		int u,v;
    		cin>>u>>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	memset(low,0,sizeof(low));
    	memset(num,0,sizeof(num));
    	memset(vis,0,sizeof(vis));
    	tim=res=0;
    	for (int i=1;i<=n;i++)
    		if (!num[i]) dfs(i,0);
    	if (bridge.empty()) {
    		cout<<0<<'\n';
    		continue;
    	}
    	int cur=0;
    	for (int i=1;i<=n;i++) {
    		if (!vis[i]) {
    			cur++;
    			comp[cur].clear();
    			dfs1(i,cur);
    		}
    	}
    	/*
    	for (int i=1;i<=cur;i++) {
    		for (auto x:comp[i]) cout<<x<<' ';
    		cout<<endl;
    	}*/
    	memset(f,-1,sizeof(f));
    	memset(g,0,sizeof(g));
    	for (auto [u,v]:bridge) {
    		//cout<<u<<' '<<v<<' '<<root[u]<<' '<<root[v]<<endl;
    		tree[root[u]].push_back(root[v]);
    		tree[root[v]].push_back(root[u]);
    	}
    	for (int i=1;i<=n;i++) 
    		if (f[i]==-1) dfs2(i,0);
    	cout<<bridge.size()-res+1<<'\n';
    }
}