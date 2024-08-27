#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
long long a[N+5],sum[N+5],dp[N+5][N+5],inf=1e18;
long long avg,r;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    	for (int j=0;j<=n;j++) dp[i][j]=inf;
    }
    avg=sum[n]/n;
    r=sum[n]-avg*n;
    for (long long i=1;i<=n;i++) {
    	dp[i][0]=dp[i-1][0]+abs(sum[i]-avg*i);
    	for (long long s=1;s<=min(i,r);s++) {
    		dp[i][s]=min(dp[i-1][s],dp[i-1][s-1])+abs(sum[i]-avg*i-s);
    	}
    }
    cout<<dp[n][r];
} 