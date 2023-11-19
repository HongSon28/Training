#include<bits/stdc++.h>
using namespace std;
const int N=100;
long long n,m,k,u,v,w;
long long inf=2e18,res=inf;
struct matrix{
    long long a[N+5][N+5];
} base;
matrix mul (matrix a,matrix b) {
    matrix c;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            c.a[i][j]=inf;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
            }
        }
    }
    return c;
}
matrix exp (matrix a, long long k) {
    if (k==1) return a;
    matrix ans=exp(a,k/2);
    ans=mul(ans,ans);
    if (k%2==1) ans=mul(ans,a);
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            base.a[i][j]=inf;
        }
    }
    while (m--) {
        cin>>u>>v>>w;
        base.a[u][v]=min(base.a[u][v],w);
    }
    base=exp(base,k);
    for (int i=1;i<=n;i++) {
        res=min(res,base.a[i][i]);
    }
    if (res==inf) cout<<-1;
    else cout<<res;
}
