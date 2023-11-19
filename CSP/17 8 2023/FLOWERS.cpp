#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct dat{
    long long t,d;
    double x;
    bool operator < (const dat & others) const {
        return x>others.x;
    }
};
int n;
dat a[N+5];
long long total_time,flower,cur,res;
int main() {
    freopen("FLOWERS.INP","r",stdin);
    freopen("FLOWERS.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].t>>a[i].d;
    for (int i=1;i<=n;i++) a[i].x=(double) a[i].d/a[i].t;
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        res+=cur*a[i].d;
        cur+=a[i].t*2;
    }
    cout<<res;
}
