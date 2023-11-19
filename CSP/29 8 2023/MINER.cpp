#include<bits/stdc++.h>
using namespace std;
const int N=1e3,MX=__lg(N);
int a[N+5][N+5],b[N+5][N+5];
int m,n,k;
int st[MX+5][N+5][MX+5][N+5],inf=1e9;
int getMax(int x, int y, int a, int b) {
    int k = __lg(a - x + 1);
    int l = __lg(b - y + 1);
    return max({ st[k][x][l][y],
                 st[k][x][l][b - (1 << l) + 1],
                 st[k][a - (1 << k) + 1][l][y],
                 st[k][a - (1 << k) + 1][l][b - (1 << l) + 1] });
}
void preprocess() {
    for (int k=0;k<=MX;k++) {
        for (int i=1;i+(1<<k)-1<=N;i++) {
            for (int l=0;l<=MX;l++) {
                for (int j=1;j+(1<<l)-1<=N;++j) {
                    if (k==0) {
                        if (l==0) st[0][i][0][j]=b[i][j];
                        else st[0][i][l][j]=max(st[0][i][l-1][j],st[0][i][l-1][j+(1<<(l-1))]);
                    }
                    else {
                        st[k][i][l][j] = max(st[k-1][i][l][j],st[k-1][i+(1<<(k-1))][l][j]);
                    }
                }
            }
        }
    }
}
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
    preprocess();
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            int u=i-j+n,v=i+j;
            int u1=max(u-k,1),v1=max(v-k,1);
            int u2=min(u+k,m+n-1),v2=min(v+k,m+n);
            cout<<getMax(u1,v1,u2,v2)<<' ';
        }
        cout<<'\n';
    }
}

