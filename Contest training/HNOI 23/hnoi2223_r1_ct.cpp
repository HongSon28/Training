#include<bits/stdc++.h>
using namespace std;
const int N=500,maxN=1e5;
int dp[N+5][2][maxN+5];
int n;
int a[N+5];
int res=1e9,inf=1e9,sum;
int main() {
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    for (int i=0;i<=N;i++)
        for (int j=0;j<=maxN;j++)
            dp[i][0][j]=dp[i][1][j]=inf;
    dp[0][0][0]=0,dp[0][1][0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=maxN;j++) {
            if (dp[i-1][0][j]!=inf) {
                dp[i][0][j]=dp[i-1][0][j]+a[i];
            }
            if (dp[i-1][1][j]!=inf) {
                dp[i][1][j]=dp[i-1][1][j]+a[i];
            }
        }
        for (int j=maxN;j>=0;j--) {
            if (dp[i-1][0][j]!=inf) {
                dp[i][0][j+a[i]]=min(dp[i][0][j+a[i]],dp[i-1][0][j]);
            }
            if (dp[i-1][1][j]!=inf) {
                dp[i][1][j+a[i]]=min(dp[i][1][j+a[i]],dp[i-1][1][j]);
            }
        }
        for (int j=0;j<=maxN;j++) {
            if (dp[i-1][0][j]!=inf) {
                if (j>=a[i]) dp[i][0][j-a[i]]=min(dp[i][0][j-a[i]],dp[i-1][0][j]);
                else dp[i][1][a[i]-j]=min(dp[i][1][a[i]-j],dp[i-1][0][j]);
                if (i==n&&j==a[i]) res=min({res,dp[i][0][0],dp[i][1][0]});
            }
            if (dp[i-1][1][j]!=inf) {
                if (j>=a[i]) dp[i][1][j-a[i]]=min(dp[i][1][j-a[i]],dp[i-1][1][j]);
                else dp[i][0][a[i]-j]=min(dp[i][0][a[i]-j],dp[i-1][1][j]);
                if (i==n&&j==a[i]) res=min({res,dp[i][0][0],dp[i][1][0]});
            }
        }
    }
    cout<<(sum-res)/2;
}
