#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long p[N+1];
long long dp[N+1][(1<<10)],bit[N+1],res,inf=1e18;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>p[i];
    }
    while (m--) {
        int u,v;
        cin>>u>>v;
        bit[v]|=(1<<(v-u-1));
    }
    for (int i=0;i<=N;i++)
        for (int j=0;j<(1<<10);j++)
            dp[i][j]=-inf;
    dp[0][0]=0;
    for (int i=0;i<n;i++) {
        for (int mask=0;mask<(1<<10);mask++) {
            if (dp[i][mask]==-inf) continue;
            int m1=(mask&511)*2;
            dp[i+1][m1]=max(dp[i+1][m1],dp[i][mask]);
            if ((mask&bit[i+1])==bit[i+1]) {
                dp[i+1][m1+1]=max(dp[i][mask]+p[i+1],dp[i+1][m1+1]);
            }
        }
    }
    //cout<<dp[1][1]<<' '<<dp[2][3]<<' '<<dp[3][7]<<' '<<dp[4][14]<<' '<<dp[5][29]<<endl;
    for (int mask=0;mask<(1<<10);mask++) res=max(res,dp[n][mask]);
    cout<<res;
}
