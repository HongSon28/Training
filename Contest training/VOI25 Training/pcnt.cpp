#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,k;
long long dp[N+5][N+5],mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	dp[1][0]=1;
	for (int i=2;i<=n;i++) {
		dp[i][0]=dp[i-1][0];
		for (int j=1;j<=k;j++) {
			dp[i][j]=(j+1)*dp[i-1][j]%mod;
			dp[i][j]+=dp[i-1][j-1]*(i-j);
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][k];
}