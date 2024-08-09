#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,k;
int a[N+5][N+5],sum[N+5][N+5],res;
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for (int i=k;i<=n;i++) {
        for (int j=k;j<=n;j++) {
            int u=i-k+1,v=j-k+1;
            res=max(res,sum[i][j]-sum[i][v-1]-sum[u-1][j]+sum[u-1][v-1]);
        }
    }
    cout<<res;
}
