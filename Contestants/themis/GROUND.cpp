#include<bits/stdc++.h>
using namespace std;
const int N=1e3,MX=__lg(N);
int a[N+1][N+1];
int m,n,kk;
pair<int,int> st[MX+1][N+1][MX+1][N+1];
int res=INT_MAX;
#define fi first
#define se second
int getMax(int x, int y, int u, int v) {
    int k=__lg(u-x+1);
    int l=__lg(v-y+1);
    return max({ st[k][x][l][y].fi,
                 st[k][x][l][v-(1<<l)+1].fi,
                 st[k][u-(1<<k)+1][l][y].fi,
                 st[k][u-(1<<k)+1][l][v-(1<<l)+1].fi});
}
int getMin(int x, int y, int u, int v) {
    int k = __lg(u-x+1);
    int l = __lg(v-y+1);
    return min({ st[k][x][l][y].se,
                 st[k][x][l][v-(1<<l)+1].se,
                 st[k][u-(1<<k)+1][l][y].se,
                 st[k][u-(1<<k)+1][l][v-(1<<l)+1].se});
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n>>kk;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int k=0;k<=MX;k++) {
        for (int i=1;i+(1<<k)-1<=m;i++) {
            for (int l=0;l<=MX;l++) {
                for (int j=1;j+(1<<l)-1<=n;j++) {
                    if (k==0) {
                        if (l==0) {
                            st[0][i][0][j].fi=a[i][j];
                            st[0][i][0][j].se=a[i][j];
                        }
                        else {
                            st[0][i][l][j].fi=max(st[0][i][l-1][j].fi,st[0][i][l-1][j+(1<<(l-1))].fi);
                            st[0][i][l][j].se=min(st[0][i][l-1][j].se,st[0][i][l-1][j+(1<<(l-1))].se);
                        }
                    }
                    else {
                        st[k][i][l][j].fi=max(st[k-1][i][l][j].fi,st[k-1][i+(1<<(k-1))][l][j].fi);
                        st[k][i][l][j].se=min(st[k-1][i][l][j].se,st[k-1][i+(1<<(k-1))][l][j].se);
                    }
                }
            }
        }
    }
    for (int i=1;i<=m-kk+1;i++) {
        for (int j=1;j<=n-kk+1;j++) {
            int u=i+kk-1,v=j+kk-1;
            int t1=getMax(i,j,u,v);
            int t2=getMin(i,j,u,v);
            res=min(res,t1-t2);
        }
    }
    cout<<res;
}


