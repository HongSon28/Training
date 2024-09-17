#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int a[N+5];
int dp[N+5][N+5][N+5][2],inf=1e9;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int c0=0;c0<=n/2;c0++) {
		for (int c1=0;c1<=(n+1)/2;c1++) {
			dp[0][c0][c1][0]=dp[0][c0][c1][1]=inf;
		}
	}
	dp[0][0][0][0]=dp[0][0][0][1]=0;
	for (int i=1;i<=n;i++) {
		for (int c0=0;c0<=n/2;c0++) {
			for (int c1=0;c1<=(n+1)/2;c1++) {
				dp[i][c0][c1][0]=dp[i][c0][c1][1]=inf;
				if (a[i]!=0) {
					if (a[i]%2&&c1>0) dp[i][c0][c1][1]=min(dp[i-1][c0][c1-1][1],dp[i-1][c0][c1-1][0]+1);
					if (a[i]%2==0&&c0>0) dp[i][c0][c1][0]=min(dp[i-1][c0-1][c1][1]+1,dp[i-1][c0-1][c1][0]);
				} else {
					if (c0>0) 
						dp[i][c0][c1][0]=min(dp[i-1][c0-1][c1][1]+1,dp[i-1][c0-1][c1][0]);
					if (c1>0)
						dp[i][c0][c1][1]=min(dp[i-1][c0][c1-1][1],dp[i-1][c0][c1-1][0]+1);
				}
				//cout<<i<<' '<<c0<<' '<<c1<<' '<<dp[i][c0][c1][0]<<' '<<dp[i][c0][c1][1]<<endl;
			}
		}
	}
	cout<<min(dp[n][n/2][(n+1)/2][0],dp[n][n/2][(n+1)/2][1]);
}