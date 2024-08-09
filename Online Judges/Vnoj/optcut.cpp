#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
long long a[N+5],c[N+5][N+5],sum[N+5];
long long dp[N+5][N+5];
int opt[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	dp[i][i]=0;
    	opt[i][i]=i;
    	sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<n;i++) 
    	for (int j=i+1;j<=n;j++)
    		c[i][j]=sum[j]-sum[i-1];
    for (int len=2;len<=n;len++) {
    	for (int i=1;i+len-1<=n;i++) {
    		int j=i+len-1;
    		dp[i][j]=1e18;
    		for (int k=opt[i][j-1];k<=min(j-1,opt[i+1][j]);k++) {
    			if (dp[i][j]>dp[i][k]+dp[k+1][j]+c[i][j]) {
    				dp[i][j]=dp[i][k]+dp[k+1][j]+c[i][j];
    				opt[i][j]=k;
    			}
    		}
    	}
    }
    cout<<dp[1][n];
}