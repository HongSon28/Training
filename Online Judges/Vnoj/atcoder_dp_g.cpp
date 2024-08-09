#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<vector<int>>adj(N+5);
int dp[N+5],res;
void dfs(int u) {
	if (dp[u]!=-1) return;
	dp[u]=0;
	for (auto v:adj[u]) {
		dfs(v);
		dp[u]=max(dp[u],dp[v]+1);
	}
	res=max(res,dp[u]);
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
	cout<<res;
}