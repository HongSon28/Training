#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,mod=1e6+1,dp[51][101];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>m>>n>>k;
    	dp[0][0]=1;
    	for (int i=1;i<=m;i++) {
    		dp[i][0]=1;
    		for (int j=1;j<=k;j++) {
    			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(n-j+1);
    			dp[i][j]%=mod;
    		}
    	}
    	cout<<dp[m][k]<<'\n';
    }	
}
