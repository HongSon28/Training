#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n,m;
long long a[N+5][N+5],sum[N+5][N+5];
long long res=-1e18;
long long getsum(int i,int j,int u,int v) {
    return sum[u][v]-sum[i-1][v]-sum[u][j-1]+sum[i-1][j-1];
}
int main() {
    freopen("MAXFRAME.INP","r",stdin);
    freopen("MAXFRAME.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for (int i=1;i<n;i++)
         for (int j=1;j<m;j++)
             res=max(res,a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1]);
    for (int i=1;i<=n;i++) {
        for (int u=i+1;u<=n;u++) {
            long long temp=getsum(i,1,u,1)-a[i][1]-a[u][1];
            int v;
            for (int j=2;j<=m;j++) {
                res=max(res,temp+getsum(i,1,i,j-1)+getsum(u,1,u,j-1)+getsum(i,j,u,j));
                v=j;
                temp=max(temp,getsum(i,v,u,v)-getsum(i,1,i,v)-getsum(u,1,u,v));
            }
        }
    }
    cout<<res;
}
