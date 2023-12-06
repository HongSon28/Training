#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
int a[N+5],b[N+5];
int dp[N+5][N+5];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=1;i<=n;i++) {
        if (a[i]==b[1]) {
            dp[i][1]=1;
        } else {
            dp[i][1]=max(dp[i-1][1],dp[i][0]);
        }
    }
    for (int i=1;i<=m;i++) {
        if (a[1]==b[i]) {
            dp[1][i]=1;
        } else {
            dp[1][i]=max(dp[0][i],dp[1][i-1]);
        }
    }
    for (int i=2;i<=n;i++) {
        for (int j=2;j<=m;j++) {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if (a[i]==b[j]) {
                dp[i][j]=max(dp[i][j],dp[i-2][j-2]+1);
            }
        }
    }
    cout<<dp[n][m];
}
