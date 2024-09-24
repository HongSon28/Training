#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<vector<int>>adj(N+5);
long long dp[N+5],mod=1e9+7;
void dfs(int u) {
	if (dp[u]!=-1) return;
	dp[u]=0;
	if (u==n) {
		dp[u]=1;
		return;
	}
	for (auto v:adj[u]) {
		dfs(v);
		dp[u]+=dp[v];
		if (dp[u]>mod) dp[u]-=mod;
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
	dfs(1);
	cout<<dp[1]%mod;
}
