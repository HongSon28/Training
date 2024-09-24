#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,q;
vector<int>adj[N+5],adj2[N+5];
int num[N+5],low[N+5],tim;
vector<int>comp;
bool vis[N+5];
int root[N+5];
set<pair<int,int>>bridge;
void dfs(int u,int par) {
	bool ispar=false;
	num[u]=low[u]=++tim;
	for (auto v:adj[u]) {
		if (v==par&&!ispar) {
			ispar=true;
			continue;
		}
		if (!num[v]) {
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if (low[v]==num[v]) bridge.insert({u,v});
		} else low[u]=min(low[u],num[v]);
	}
}
void dfs2(int u) {
	vis[u]=true;
	for (auto v:adj2[u]) {
		if (!vis[v]) dfs2(v);
	}
	comp.push_back(u);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>q;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    dfs(1,0);
    for (int u=1;u<=n;u++) {
    	for (auto v:adj[u]) {
    		if (bridge.count({u,v})||bridge.count({v,u})) continue;
    		adj2[u].push_back(v);
    		adj2[v].push_back(u);
    	}
    }
    int cnt=0;
    for (int i=1;i<=n;i++) {
    	if (vis[i]) continue;
    	cnt++;
    	comp.clear();
    	dfs2(i);
    	for (auto v:comp) root[v]=cnt;
    }
    //for (int i=1;i<=n;i++) cout<<root[i]<<' ';
    while (q--) {
    	int u,v;
    	cin>>u>>v;
    	if (root[u]==root[v]) cout<<"YES"<<'\n';
    	else cout<<"NO"<<'\n';
    }
}