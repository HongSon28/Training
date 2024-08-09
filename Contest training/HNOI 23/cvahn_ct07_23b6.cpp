#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
vector<int>b(N+1,INT_MAX),c(N+1,INT_MAX),f(N+1),g(N+1);
int res,en;
int main() {
    freopen("WAVIO.INP","r",stdin);
    freopen("WAVIO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    b[0]=c[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        f[i]=k;
    }
    for (int i=n;i>=1;i--) {
        int k=lower_bound(c.begin(),c.end(),a[i])-c.begin();
        c[k]=a[i];
        g[i]=k;
        cout<<i<<' '<<f[i]<<' '<<g[i]<<endl;
        if (f[i]>=k) res=max(res,k+k-1);
    }
    cout<<res;
}
