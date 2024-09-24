#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<vector<int>>adj(N+5);
int dp[N+5],trace[N+5],inf=1e9;
void dfs(int u) {
	if (dp[u]!=-1) return;
	dp[u]=-inf;
	if (u==n) dp[u]=1;
	for (auto v:adj[u]) {
		dfs(v);
		if (dp[v]!=-inf&&dp[u]<dp[v]+1) {
			dp[u]=dp[v]+1;
			trace[u]=v;
		}
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
	}
	memset(dp,-1,sizeof(dp));
	for (int i=1;i<=n;i++) dfs(i);
	if (dp[1]==-inf) {
		cout<<"IMPOSSIBLE";
		return 0;
	}
	cout<<dp[1]<<'\n';
	int u=1;
	for (int i=1;i<=dp[1];i++) {
		cout<<u<<' ';
		u=trace[u];
	}
}
