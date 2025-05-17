#include<bits/stdc++.h>
using namespace std;
const int N=400;
int q,n;
int a[N+5];
int dp[N+5][N+5],inf=1e9;
int mn[N+5];
void solve() {
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		mn[0]=dp[i-1][0];
		for (int j=1;j<=2*n;j++) mn[j]=min(mn[j-1],dp[i-1][j]);
		for (int j=i;j<=2*n;j++) dp[i][j]=mn[j-1]+abs(a[i]-j);
		for (int j=0;j<i;j++) dp[i][j]=inf;
	}
	int res=inf;
	for (int j=n;j<=2*n;j++) res=min(res,dp[n][j]);
	cout<<res<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
    while (q--) solve();
}