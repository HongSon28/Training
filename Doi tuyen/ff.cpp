#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m;
long long v[N+5],dp[N+5][105],inf=1e18,res=inf;
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>v[i];
    for (int i=1;i<=N+1;i++)
        for (int j=0;j<=101;j++)
            dp[i][j]=inf;
    for (int i=1;i<=m;i++) dp[i][i]=v[i];
    for (int i=1;i<=n+1;i++) {
        for (int j=max(1,i-m+1);j<i;j++) {
            for (int k=1;k<=m;k++) {
                int l=j-k;
                if (l<max(0,i-m)) continue;
                dp[i][i-j]=min(dp[i][i-j],dp[j][k]+v[i]);
            }
            if (i==n+1) res=min(res,dp[i][i-j]);
        }
    }
    cout<<res;
}
