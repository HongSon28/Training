#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long c;
vector<int>adj[N+5];
long long a[N+5],dp[N+5][2];
void dfs(int u,int par) {
	dp[u][0]=0;
	dp[u][1]=a[u];
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		dp[u][1]+=max(dp[v][0],dp[v][1]-2*c);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>c;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		adj[i].clear();
    	}
    	for (int i=1;i<n;i++) {
    		int u,v;
    		cin>>u>>v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	dfs(1,0);
    	cout<<max(dp[1][0],dp[1][1])<<'\n';
    }
}