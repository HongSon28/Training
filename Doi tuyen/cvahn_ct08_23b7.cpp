#include<bits/stdc++.h>
using namespace std;
const int N=500;
long long m,n,r,d,h;
long long a[N+5][N+5],sum[N+5][N+5];
long long res=1e18;
int main() {
    freopen("DUONGBANG.INP","r",stdin);
    freopen("DUONGBANG.OUT","w",stdout);
    cin>>m>>n>>d>>r>>h;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+abs(h-a[i][j]);
        }
    }
    for (int i=d;i<=m;i++) {
        for (int j=r;j<=n;j++) {
            int u=i-d+1,v=j-r+1;
            long long temp=sum[i][j]-sum[u-1][j]-sum[i][v-1]+sum[u-1][v-1];
            res=min(res,temp);
        }
    }
    swap(d,r);
    for (int i=d;i<=m;i++) {
        for (int j=r;j<=n;j++) {
            int u=i-d+1,v=j-r+1;
            long long temp=sum[i][j]-sum[u-1][j]-sum[i][v-1]+sum[u-1][v-1];
            res=min(res,temp);
        }
    }
    cout<<res;
}
/*
5 6 4 2 2
3 4 2 4 3 3
4 5 2 2 5 3
1 4 3 2 5 4
3 4 2 1 5 3
3 4 2 3 1 5
*/
