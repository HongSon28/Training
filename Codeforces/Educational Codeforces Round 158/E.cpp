#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long inf=1e18;
int t,n;
long long a[N+5],dp[N+5][4],res;
vector<vector<int>>adj(N+5);
void dfs(int u,int par) {
	vector<long long>cur;
	for (auto v:adj[u])  {
		if (v==par) continue;
		dfs(v,u);
		long long temp=max({dp[v][0],dp[v][1],dp[v][2],dp[v][3]});
		cur.push_back(temp);
	} 
	dp[u][0]=a[u];
	sort(cur.rbegin(),cur.rend());
	if(cur.size()>0) dp[u][1]=cur[0];
    if(cur.size()>1) dp[u][2]=cur[0]+cur[1]+a[u];
    if(cur.size()>2) {
        dp[u][3]=cur[0]+cur[1]+cur[2]+a[u];
        for(int i=3;i<(int)cur.size();i++) dp[u][3]+=max(0ll,cur[i]);
    }
    res=max({res,dp[u][0],dp[u][1]+a[u],dp[u][2]-a[u],dp[u][3]});
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=-inf;
			adj[i].clear();
		}
		for (int i=1;i<n;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		res=0;
		dfs(1,0);
		cout<<res<<'\n';
	}
}