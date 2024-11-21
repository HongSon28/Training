#include<bits/stdc++.h>
using namespace std;
int t,n,sa,sb;
int dp[12][12];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>sa>>sb;
    	memset(dp,0,sizeof(dp));
    	dp[0][0]=1;
    	for (int i=0;i<=sa;i++) {
    		for (int j=0;j<=sb;j++) {
    			if ((i>=n||j>=n)&&(abs(i-j)>=2)) continue;
    			dp[i+1][j]+=dp[i][j];
    			dp[i][j+1]+=dp[i][j];
    		}
    	}
    	if ((sa<n&&sb<n)||(abs(sa-sb)<2)) cout<<0<<'\n';
    	else cout<<dp[sa][sb]<<'\n';
    }
}