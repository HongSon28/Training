#include<bits/stdc++.h>
using namespace std;
const int N=5e4,M=500;
int n,k;
vector<int>adj[N+5];
long long res,dp[N+5][M+5];
void dfs(int u,int par) {
	dp[u][0]++;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		for (int i=1;i<=k;i++) {
			res+=dp[u][k-i]*dp[v][i-1];
			//cout<<u<<' '<<v<<' '<<i<<' '<<dp[u][k-i]<<' '<<dp[v][i-1]<<' '<<res<<endl;
		}
		for (int i=1;i<=k;i++) dp[u][i]+=dp[v][i-1];
	}
	//res+=dp[u][k];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    dfs(1,0);
    cout<<res;
}