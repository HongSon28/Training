#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],dp[3][N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][1]=0,dp[1][1]=a[1];
    for (int i=2;i<=n;i++) {
        dp[0][i]=max({dp[0][i-1],dp[1][i-1],dp[2][i-1]});
        dp[1][i]=dp[0][i-1]+a[i];
        dp[2][i]=dp[1][i-1]+a[i];
    }
    cout<<max({dp[0][n],dp[1][n],dp[2][n]});
}
