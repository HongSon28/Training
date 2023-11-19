#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int a[N+5][N+5],b[2*N+5][2*N+5],sum[2*N+5][2*N+5];
int m,n;
int res;
bool check(int k) {
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            int u=i-j+n,v=i+j;
            int u1=u-k,v1=v-k,u2=u+k,v2=v+k;
            if (u1<1||v1<1||u2>m+n-1||v2>m+n) continue;
            int t1=sum[u2][v2]-sum[u2][v1-1]-sum[u1-1][v2]+sum[u1-1][v1-1];
            int t2=((u2-u1+1)*(v2-v1+1)+1)/2;
            if (t1==t2) return true;
        }
    }
    return false;
}
int main() {
    freopen("MAXR.INP","r",stdin);
    freopen("MAXR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            int u=i-j+n;
            int v=i+j;
            b[u][v]=a[i][j];
        }
    }
    for (int i=1;i<=2*N;i++)
        for (int j=1;j<=2*N;j++)
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
    int lo=1,hi=min(m,n)/2;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}
