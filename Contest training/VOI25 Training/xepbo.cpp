#include<bits/stdc++.h>
using namespace std;
const int N=4e3;
int n,m;
long long a[N+5],b[N+5],dp[N+5][N+5],inf=1e18;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    cin>>m;
    for (int i=1;i<=m;i++) cin>>b[i];
	sort(b+1,b+1+m);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++) dp[i][j]=inf;
	dp[0][0]=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) 
			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+abs(a[i]-b[j]);
	}
	cout<<dp[n][m];
}