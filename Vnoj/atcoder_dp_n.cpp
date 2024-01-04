#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n;
long long a[N+5],dp[N+5][N+5],sum[N+5],inf=1e18;
int opt[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    	opt[i-1][i]=i-1;
    	dp[i-1][i]=a[i-1]+a[i];
    }
    for (int len=3;len<=n;len++) {
    	for (int i=1;i+len-1<=n;i++) {
    		int j=i+len-1;
    		dp[i][j]=inf;
    		for (int k=opt[i][j-1];k<=opt[i+1][j];k++) {
    			if (dp[i][j]>dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]) {
    				dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
    				opt[i][j]=k;
    			}
    		}
    	}
    }
    cout<<dp[1][n];
}