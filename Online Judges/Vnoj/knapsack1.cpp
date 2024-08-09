#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n,W;
    cin>>n>>W;
    long long w[n+1];
    long long c[n+1];
    for (int i=1;i<=n;i++) cin>>w[i]>>c[i];
    long long dp[n+1][W+1];
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
