#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,k,a[N+4][N+4],sum[N+5][N+5],b[2*N+3][2*N+3],c[N+4][N+4];
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            b[i-j+n][i+j]=a[i][j];
        }
    }
    for(int i=1;i<=2*n-1;i++)
        for(int j=1;j<=2*n;j++) sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int u=i-j+n,v=i+j;
            int u1=max(1,u-k), v1=max(1,v-k);
            int u2=min(u+k,2*n-1), v2=min(v+k,2*n);
            c[i][j]=sum[u2][v2]-sum[u2][v1-1]-sum[u1-1][v2]+sum[u1-1][v1-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<c[i][j]<<' ';
        cout<<'\n';
    }
}