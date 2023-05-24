#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5;
ll n,m;
ll sum;
ll a[N+5];
bool check(ll mid) {
    ll s=0;
    for (int i=1;i<=m;i++) {
        if (a[i]%mid==0) s+=a[i]/mid;
        else s+=a[i]/mid+1;
    }
    if (s>n) return false;
    return true;
}
int main() {
    freopen("G.INP","r",stdin);
    freopen("G.OUT","w",stdout);
    cin>>n>>m;
    for (ll i=1;i<=m;i++) {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+m);
    ll lo=1,hi=sum;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (check(mid)==true) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
}
