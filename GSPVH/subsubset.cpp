#include<bits/stdc++.h>
using namespace std;
const int N=2207,M=5603;
int n,m;
int c[N+5];
long long dp[N+5][2][M+5],mod=998244353;
long long res;
int main() {
	freopen("subsubset.inp","r",stdin);
	freopen("subsubset.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>c[i];
    dp[0][0][0]=1;
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<=m;j++) {
    		dp[i][0][j]=dp[i-1][0][j];
    		dp[i][1][j]=(dp[i-1][0][j]+dp[i-1][1][j]*2)%mod;
    		if (j>=c[i]) {
    			dp[i][0][j]+=dp[i-1][0][j-c[i]];
    			dp[i][0][j]%=mod;
    			dp[i][1][j]+=dp[i-1][1][j-c[i]];
    			dp[i][1][j]%=mod;
    		}
    		//cout<<i<<' '<<j<<' '<<dp[i][0][j]<<' '<<dp[i][1][j]<<endl;
    	}
    }
    for (int i=0;i<=m;i++) {
    	res+=dp[n][1][i];
    	res%=mod;
    }
    cout<<res;
}