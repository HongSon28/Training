#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
vector<vector<int>>adj(N+5);
long long dp[N+5][2],mod=1e9+7;
void dfs(int u,int par) {
	dp[u][0]=dp[u][1]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		dp[u][0]*=dp[v][1];
		dp[u][1]*=(dp[v][0]+dp[v][1])%mod;
		dp[u][0]%=mod;
		dp[u][1]%=mod;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,-1);
	cout<<(dp[1][0]+dp[1][1])%mod;
}