#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
long long n,W;
long long w[N+1];
long long c[N+1];
long long dp[N+1][N+1];
int main() {
    freopen("TRAVEL.INP","r",stdin);
    freopen("TRAVEL.OUT","w",stdout);
    cin>>n>>W;
    for (int i=1;i<=n;i++) cin>>w[i]>>c[i];
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=0;i<=W;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=W;j++) {
            dp[i][j]=dp[i-1][j];
            if (j>=w[i]&&dp[i-1][j-w[i]]+c[i]>dp[i][j])
                dp[i][j]=dp[i-1][j-w[i]]+c[i];
        }
    }
    cout<<dp[n][W];
}

