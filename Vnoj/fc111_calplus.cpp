#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n;
long long a[N+5],dp[N+5][N+5],sum[N+5];
int opt[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	opt[i][i]=i;
    	sum[i]=sum[i-1]+a[i];
    }
    for (int i=n-1;i>=1;i--) {
    	for (int j=i+1;j<=n;j++) {
    		long long mn=LLONG_MAX;
    		for (int k=opt[i][j-1];k<=min(j-1,opt[i+1][j]);k++) {
    			if (mn>dp[i][k]+dp[k+1][j]+(sum[j]-sum[i-1])*(sum[j]-sum[i-1])) {
    				mn=dp[i][k]+dp[k+1][j]+(sum[j]-sum[i-1])*(sum[j]-sum[i-1]);
    				opt[i][j]=k;
    			}
    		}
    		dp[i][j]=mn;
    	}
    }
    cout<<dp[1][n];
}