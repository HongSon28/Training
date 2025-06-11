#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
long long a[N+5];
long long dp[N+5][N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i][1]=max(dp[i-1][1],a[i]);
    }
    for (int i=3;i<=n;i++) {
        for (int j=2;j<=(i+1)/2;j++) dp[i][j]=max(dp[i-1][j],dp[i-2][j-1]+a[i]);
    }
    for (int i=1;i<=(n+1)/2;i++) cout<<dp[n][i]<<'\n';
}
