#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
int n,m;
vector<int>adj[N+5];
int low[N+5],num[N+5],tim;
bool vis[N+5];
long long sz[N+5],res;
void dfs(int u,int par) {
	sz[u]=1;
	vis[u]=true;
	num[u]=low[u]=++tim;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (!num[v]) {
			dfs(v,u);
			sz[u]+=sz[v];
			low[u]=min(low[u],low[v]);
		} else low[u]=min(low[u],num[v]);
	}
}
void dfs2(int u,int par,int root) {
	vis[u]=true;
	vector<long long>cur;
	long long sum=sz[root]-1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (!vis[v]) {
			dfs2(v,u,root);
			if (u==par||low[v]>=num[u]) {
				cur.push_back(sz[v]);
				sum-=sz[v];
			} 
		}
	}
	cur.push_back(sum);
	sum=cur[0];
	for (int i=1;i<(int)cur.size();i++) {
		res+=sum*cur[i];
		sum+=cur[i];
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
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
    	if (!vis[i]) dfs(i,i);
    }
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n;i++)
    	if (!vis[i]) dfs2(i,i,i);
    double ans=(double)res/(double)n;
    cout<<fixed<<ans;
}