#include<bits/stdc++.h>
using namespace std;
const int N=1e3,MX=__lg(N);
int a[N+5][N+5],b[N+5][N+5];
int m,n,k;
int rmq[N+5][N+5][MX+5],inf=1e9;
int main() {
    freopen("MINER.INP","r",stdin);
    freopen("MINER.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>k;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            int u=i-j+n,v=i+j;
            b[u][v]=a[i][j];
        }
    }
    for (int i=1;i<=m+n-1;i++)
        for (int j=1;j<=m+n;j++)
            rmq[i][j][0]=b[i][j];
    for (int i=1;i<=m+n-1;i++) {
        for (int j=1;j<=MX;j++) {
            for (int p=1;p<=m+n-(1<<j)+1;p++) {
                rmq[i][p][j]=max(rmq[i][p][j-1],rmq[i][p+(1<<(j-1))][j-1]);
            }
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            int u=i-j+n,v=i+j;
            int u1=max(u-k,1),v1=max(v-k,1);
            int u2=min(u+k,m+n-1),v2=min(v+k,m+n);
            int res=-inf;
            int len=v2-v1+1;
            int lg=__lg(len);
            for (int t=u1;t<=u2;t++) res=max(res,max(rmq[t][v1][lg],rmq[t][v2-(1<<lg)+1][lg]));
            cout<<res<<' ';
        }
        cout<<'\n';
    }
}

