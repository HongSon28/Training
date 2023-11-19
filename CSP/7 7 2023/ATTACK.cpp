#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const int N=1e5;
ll n,k;
ll a[N+5],b[N+5];
ll lo,hi,res;
bool check(ll m) {
    ll cnt=0;
    for (int i=1;i<=n;i++) {
        if (m<a[i]) continue;
        cnt+=(m-a[i])/b[i]+1;
    }
    if (cnt<=k) return true;
    return false;
}
int main() {
    freopen("ATTACK.INP","r",stdin);
    freopen("ATTACK.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
    lo=0,hi=1e19;
    while (lo<=hi) {
        ll mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res+1;
}
