#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
long long mod;
long long power[N*N+5];
long long dp[N+5][N+5];
long long f[N+5][N+5],C[N+5][N+5];
long long binpow(long long x,long long y) {
	if (y==1) return x;
	long long ans=binpow(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=(ans*x)%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>mod;
    power[0]=1;
    for (int i=1;i<=N*N;i++) power[i]=power[i-1]*2%mod;
    for (int i=1;i<=N;i++) {
    	for (int j=1;j<=N;j++) {
    		long long t=power[i]-1;
    		if (t<0) t+=mod;
    		f[i][j]=binpow(t,j);
    	}
    }
    for (int i=0;i<=N;i++) C[0][i]=1;
    for (int i=1;i<=N;i++) C[1][i]=i;
    for (int i=2;i<=N;i++) {
    	for (int j=i;j<=n;j++) C[i][j]=(C[i-1][j-1]+C[i][j-1])%mod;
    }
    dp[1][1]=1;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=i;j++) {
    		if (!dp[i][j]) continue;
    		for (int k=1;k+i<=n;k++) {
    			long long tc=C[k][n-i-1];
    			if (k==1&&i+k==n) tc=1;
    			dp[i+k][k]+=dp[i][j]*power[k*(k-1)/2]%mod*f[j][k]%mod*tc%mod;
    			dp[i+k][k]%=mod;
    			//cout<<i+k<<' '<<k<<' '<<dp[i+k][k]<<endl;
    		}
    	}
    }
    cout<<dp[n][1];
}