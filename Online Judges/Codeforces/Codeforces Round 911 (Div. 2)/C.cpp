#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int t,n;
string s;
int l[N+5],r[N+5],dp[N+5];
void dfs(int u) {
	if (l[u]==0&&r[u]==0) {
		dp[u]=0;
		return;
	}
	if (l[u]!=0) dfs(l[u]);
	if (r[u]!=0) dfs(r[u]);
	if (s[u]=='U') {
		dp[u]=INT_MAX;
		if (l[u]!=0) dp[u]=min(dp[u],dp[l[u]]+1);
		if (r[u]!=0) dp[u]=min(dp[u],dp[r[u]]+1);
	} else if (s[u]=='L') {
		if (l[u]==0) dp[u]=INT_MAX;
		else dp[u]=dp[l[u]];
		if (r[u]!=0) dp[u]=min(dp[u],dp[r[u]]+1);
	} else if (s[u]=='R') {
		if (r[u]==0) dp[u]=INT_MAX;
		else dp[u]=dp[r[u]];
		if (l[u]!=0) dp[u]=min(dp[u],dp[l[u]]+1);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n>>s;
		s=' '+s;
		for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
		dfs(1);
		cout<<dp[1]<<'\n';
	}
}