#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
long long a[N+5],sum[N+5],dp[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=3;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			dp[i][i]=a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for (int len=2;len<=n;len++) {
			for (int l=1;l+len-1<=n;l++) {
				int r=l+len-1;
				dp[l][r]=sum[r]-sum[l-1];
				for (int k=l;k<r;k++) dp[l][r]=max(dp[l][r],sum[r]-sum[l-1]-dp[k+1][r]);
				for (int k=r;k>l;k--) dp[l][r]=max(dp[l][r],sum[r]-sum[l-1]-dp[l][k-1]);
			}
		}
		cout<<dp[1][n]<<'\n';
	}	
}