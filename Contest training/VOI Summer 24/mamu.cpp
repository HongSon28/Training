#include<bits/stdc++.h>
using namespace std;
const int N=100;
int t,n;
long long a[N+5];
long long dp[N+5][N+5],inf=1e18;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n+1;i++) {
			cin>>a[i];
			dp[i][i]=0;
		}
		for (int len=2;len<=n;len++) {
			for (int i=1;i+len-1<=n;i++) {
				int j=i+len-1;
				dp[i][j]=inf;
				for (int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1]);
			}
		}
		cout<<dp[1][n]<<'\n';
	}
}