#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
long long mod=1e9+7;
long long n,m,res;
long long dp[N+5][N+5];
int main() {
    freopen("CBN3.INP","r",stdin);
    freopen("CBN3.OUT","w",stdout);
    cin>>n>>m;
    dp[0][0]=1;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=min(i,m);j++) {
            dp[i][j]=((dp[i-1][j]*j%mod)+(dp[i-1][j-1]*(m-j+1)%mod))%mod;
            //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        }
    }
    for (int i=1;i<=min(n,m);i++) {
        res+=dp[n][i]*(i*i%mod)%mod;
        res%=mod;
    }
    cout<<res;
}
