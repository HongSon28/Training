#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll n,k;
ll a[N+5],sum[N+5];
bool check(ll m) {
    ll res=0;
    for (int i=1;i<=n;i++) {
        if (a[i]>m) continue;
        int lo=i,hi=n;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (sum[mid]-sum[i-1]<=m) lo=mid;
            else hi=mid-1;
        }
        res+=lo-i+1;
    }
    if (res>=k) return true;
    return false;
}
int main() {
    freopen("D.inp","r",stdin);
    freopen("D.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    ll lo=0,hi=sum[n];
    while (lo<hi) {
        ll mid=(lo+hi)/2;
        if (check(mid)==true) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
}
