#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=500;
int n,sum;
int a[M+5];
int dp[M+5][2*N+5],inf=1e9;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	for (int s=-sum;s<=sum;s++) dp[0][s+N]=inf;
	dp[0][N]=0;
	for (int i=1;i<=n;i++) {
		for (int s=-sum;s<=sum;s++) {
			dp[i][s+N]=dp[i-1][s+N]+a[i];
			if (s+a[i]<=sum) dp[i][s+N]=min(dp[i][s+N],dp[i-1][s+a[i]+N]);
			if (s-a[i]>=-sum) dp[i][s+N]=min(dp[i][s+N],dp[i-1][s-a[i]+N]);
		}
	}
	int res=dp[n][N];
	cout<<(sum-res)/2+res;
}