#include<bits/stdc++.h>
using namespace std;
const int N=500;
long long a[N+5][N+5],b[N+5][N+5],sum1[N+5][N+5],sum2[N+5][N+5];
long long dp[N+5][N+5];
int main() {
    //freopen("ORE.INP","r",stdin);
    //freopen("ORE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m,n;
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+a[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>b[i][j];
            sum2[i][j]=sum2[i-1][j]+sum2[i][j-1]-sum2[i-1][j-1]+b[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            dp[i][j]=max(sum1[i][j]-sum1[i-1][j]+dp[i-1][j],sum2[i][j]-sum2[i][j-1]+dp[i][j-1]);
        }
    }
    cout<<dp[m][n];
}
