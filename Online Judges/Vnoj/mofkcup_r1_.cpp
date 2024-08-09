#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
int a[N+5][N+5],dp[N+5][N+5];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
        }
    }
    dp[n][m]=a[n][m]+1;
    for (int i=m-1;i>=1;i--) {
        dp[n][i]=max(a[n][i]+1,dp[n][i+1]-a[n][i]);
    }
    for (int i=n-1;i>=1;i--) {
        for (int j=m;j>=1;j--) {
            dp[i][j]=min(max(dp[i+1][j]-a[i][j],a[i][j]+1),max(dp[i][j+1]-a[i][j],a[i][j]+1));
        }
    }
    cout<<dp[1][1];
}
