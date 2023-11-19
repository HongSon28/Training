#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
vector<int>b(N+1,INT_MAX),f(N+1),trace(N+5),p(N+5),path;
int res,en;
int main() {
    freopen("LIS.INP","r",stdin);
    freopen("LIS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        trace[i]=p[k-1];
        b[k]=a[i];
        p[k]=i;
        f[i]=k;
    }
    for (int i=1;i<=n;i++) {
        if (res<f[i]) {
            res=f[i];
            en=i;
        }
    }
    cout<<res<<endl;
    for (int i=1;i<res;i++) {
        path.push_back(en);
        en=trace[en];
    }
    cout<<en<<' ';
    for (int i=path.size()-1;i>=0;i--) cout<<path[i]<<' ';
}

