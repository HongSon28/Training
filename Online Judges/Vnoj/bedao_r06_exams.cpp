#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[N+5];
long long dp[N+5][4];
int main() {
    long long n,mod=1e9+7;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i][1]=(dp[i-1][1]+a[i])%mod;
    }
    for (int j=2;j<=3;j++) {
        for (int i=1;i<=n;i++) dp[i][j]=(dp[i-1][j]+dp[i-1][j-1]*a[i])%mod;
    }
    cout<<dp[n][3];
}
