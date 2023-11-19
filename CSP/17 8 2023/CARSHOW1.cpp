#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,t;
long long x[N+5],v[N+5],a[N+5];
int res;
int main() {
    freopen("CARSHOW1.INP","r",stdin);
    freopen("CARSHOW1.OUT","w",stdout);
    cin>>n>>t;
    res=n;
    for (int i=1;i<=n;i++) cin>>x[i]>>v[i];
    for (int i=n;i>=1;i--) a[i]=x[i]+v[i]*t;
    for (int i=n-1;i>=1;i--) {
        if (a[i]>=a[i+1]) {
            res--;
            a[i]=a[i+1];
        }
    }
    cout<<res;
}
