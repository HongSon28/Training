#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6;
ll a[N+5];
ll n,s;
bool check(ll m) {
    ll sum=0;
    for (int i=1;i<=m;i++) sum+=a[i];
    for (int i=2;i<=n-m+1;i++) {
        if (sum>=s) return true;
        sum-=a[i-1];
        sum+=a[i+m-1];
    }
    return false;
}
int main() {
    cin>>n>>s;
    for (int i=1;i<=n;i++)cin>>a[i];
    ll lo=1,hi=n;
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (check(mid)==true) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
}
