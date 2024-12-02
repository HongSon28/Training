#include<bits/stdc++.h>
using namespace std;
int n,m,q;
vector<vector<long long>>d;
namespace sub1{
    long long inf=1e18;
    vector<vector<long long>>dp;
    void solve() {
        dp.resize(n+5);
        for (int i=0;i<=n;i++) dp[i].resize(m+5);
        while (q--) {
            int x,y;
            cin>>x>>y;
            long long last=d[x][y];
            d[x][y]=-inf;
            for (int i=0;i<=n;i++)
                for (int j=0;j<=m;j++) dp[i][j]=-inf;
            dp[1][1]=d[1][1];
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=m;j++) {
                    if (i>1||j>1) dp[i][j]=max(dp[i-1][j],dp[i][j-1])+d[i][j];
                }
            }
            cout<<dp[n][m]<<'\n';
            d[x][y]=last;
        }
    }
}
namespace subfull{
    long long inf=1e18;
    vector<vector<long long>>f,g,dp,mxrow,mxcol;
    void solve() {
        f.resize(n+5),g.resize(n+5),dp.resize(n+5),mxrow.resize(n+5);
        for (int i=0;i<=n+1;i++) {
            f[i].resize(m+5);
            g[i].resize(m+5);
            dp[i].resize(m+5);
            mxrow[i].resize(m+5);
            for (int j=0;j<=m+1;j++) f[i][j]=g[i][j]=dp[i][j]=mxrow[i][j]=-inf;
        }
        mxcol.resize(m+5);
        for (int i=0;i<=m+1;i++) {
            mxcol[i].resize(n+5);
            for (int j=0;j<=n+1;j++) mxcol[i][j]=-inf;
        }
        f[1][1]=d[1][1],g[n][m]=d[n][m];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (i>1||j>1) f[i][j]=max(f[i-1][j],f[i][j-1])+d[i][j];
            }
        }
        for (int i=n;i>=1;i--) {
            for (int j=m;j>=1;j--) {
                if (i==n&&j==m) continue;
                g[i][j]=max(g[i+1][j],g[i][j+1])+d[i][j];
                dp[i][j]=f[i][j]+g[i][j]-d[i][j];
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) mxrow[i][j]=max(mxrow[i][j-1],dp[i][j]);
        }
        for (int j=1;j<=m;j++) {
            for (int i=1;i<=n;i++) mxcol[j][i]=max(mxcol[j][i-1],dp[i][j]);
        }
        while (q--) {
            int x,y;
            cin>>x>>y;
            cout<<max(mxrow[x+1][y-1],mxcol[y+1][x-1])<<'\n';
        }
    }
}
int main() {
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>q;
    d.resize(n+5);
    d[0].resize(m+5),d[n+1].resize(m+5);
    for (int i=1;i<=n;i++) {
        d[i].resize(m+5);
        for (int j=1;j<=m;j++) cin>>d[i][j];
    }
    if (n<=40&&m<=40) sub1::solve();
    else subfull::solve();
}
/*
4 5 2
0 0 0 0 0
0 1 0 0 0
0 0 0 1 0
0 0 0 0 1
1 2
2 2
*/
