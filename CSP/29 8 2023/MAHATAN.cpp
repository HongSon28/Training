#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
long long a[N+5][N+5],b[N+5][N+5],sum[N+5][N+5],res=-1e18;
int n,k;
int main() {
    freopen("MAHATAN.INP","r",stdin);
    freopen("MAHATAN.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            int u=i-j+n,v=i+j;
            b[u][v]=a[i][j];
        }
    }
    for (int i=1;i<=2*n-1;i++) {
        for (int j=1;j<=2*n;j++) {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            int u=i-j+n,v=i+j;
            int u1=max(u-k,1),v1=max(v-k,1);
            int u2=min(u+k,2*n-1),v2=min(v+k,2*n);
            res=max(res,sum[u2][v2]-sum[u2][v1-1]-sum[u1-1][v2]+sum[u1-1][v1-1]);
        }
    }
    cout<<res;
}
