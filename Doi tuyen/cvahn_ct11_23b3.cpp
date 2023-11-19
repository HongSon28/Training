#include<bits/stdc++.h>
using namespace std;
const int N=500,maxN=1e5;
int dp[2][maxN+5];
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
    for (int j=1;j<=maxN;j++)
        dp[0][j]=dp[1][j]=-inf;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=maxN;j++) {
            dp[0][j]=dp[1][j];
        }
        for (int j=0;j<=maxN;j++) {
            dp[0][abs(j-a[i])]=max(dp[0][abs(j-a[i])],dp[1][j]+a[i]);
            dp[0][j+a[i]]=max(dp[0][j+a[i]],dp[1][j]+a[i]);
        }
        for (int j=0;j<=maxN;j++) {
            dp[1][j]=dp[0][j];
        }
    }
    cout<<dp[1][0]/2;
}
