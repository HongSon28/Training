#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
pair<long long,long long>p[N+5];
long long dpx[N+5],dpy[N+5],res;
long long calc(long long x,long long y) {
    return x*x+y*y;
}
int main() {
    freopen("VECTO.INP","r",stdin);
    freopen("VECTO.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<i;j++) {
            if (calc(dpx[i],dpy[i])<calc(dpx[j]+p[i].first,dpy[j]+p[i].second)) {
                dpx[i]=dpx[j]+p[i].first;
                dpy[i]=dpy[j]+p[i].second;
            }
        }
        res=max(res,calc(dpx[i],dpy[i]));
    }
    cout<<res;
}
