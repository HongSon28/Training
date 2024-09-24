#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,q;
vector<int>adj[N+5],adj2[N+5];
int num[N+5],low[N+5],tim;
bool vis[N+5];
vector<int>comp;
long long res,mod=123456789;
long long cnt[N+5];
void dfs(int u,int par) {
	vis[u]=true;
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
			if (low[v]==num[v]) {
				adj2[u].push_back(v);
				adj2[v].push_back(u);
			}
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
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    for (int i=1;i<=n;i++) {
    	if (!vis[i]) dfs(i,0);
    }
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n;i++) {
    	if (vis[i]) continue;
    	comp.clear();
    	dfs2(i);
    	for (auto u:comp) cnt[u]=comp.size();
    }
    for (int i=1;i<=n;i++) res=(res+cnt[i]*i)%mod;
    cout<<res;
}