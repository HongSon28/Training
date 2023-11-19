#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,k;
int a[N+5],dp[N+5][N+5][N+5],mn[N+5][N+5];
int inf=4e8,res=inf;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=N;i++)
        for (int j=0;j<=N;j++)
            for (int k=0;k<=N;k++)
                dp[i][j][k]=inf;
    for (int i=0;i<=N;i++)
        for (int j=0;j<=N;j++)
            mn[i][j]=inf;
    for (int i=1;i<=n;i++) {
        for (int m=1;m<=n;m++) {
            if (a[m]>=a[i]) {
                dp[i][0][m]=min(dp[i][0][m],dp[i-1][0][m]+a[m]-a[i]);
                mn[i][0]=min(mn[i][0],dp[i][0][m]);
                if (i==n) res=min(res,dp[i][0][m]);
            }
           // cout<<i<<' '<<0<<' '<<m<<' '<<dp[i][0][m]<<endl;
        }
        for (int j=1;j<=k;j++) {
            if (j>i) break;
            for (int m=1;m<=n;m++) {
                if (a[m]>=a[i]) dp[i][j][m]=min(dp[i][j][m],dp[i-1][j][m]+a[m]-a[i]);
                if (a[m]>=a[i]) dp[i][j][m]=min(dp[i][j][m],mn[i-1][j-1]+a[m]-a[i]);
                mn[i][j]=min(mn[i][j],dp[i][j][m]);
                if (i==n) res=min(res,dp[i][j][m]);
                //cout<<i<<' '<<j<<' '<<m<<' '<<dp[i][j][m]<<endl;
            }
        }
    }
    cout<<res;
}
