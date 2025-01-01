#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
long long a[N+5],sum[N+5];
long long dp[N+5][N+5],inf=1e18;
int opt[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    	opt[i][i]=i;
    }
    for (int len=2;len<=n;len++) {
    	for (int i=1;i+len-1<=n;i++) {
    		int j=i+len-1;
    		dp[i][j]=inf;
    		for (int k=opt[i][j-1];k<=min(j-1,opt[i+1][j]);k++) {
    			long long cur=sum[j]-sum[i-1]+dp[i][k]+dp[k+1][j];
    			if (cur<dp[i][j]) {
    				dp[i][j]=cur;
    				opt[i][j]=k;
    			}
    		}
    	}
    }
    cout<<dp[1][n];
}