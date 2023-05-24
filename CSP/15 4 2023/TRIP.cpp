#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll n,del,sum,res=1e18;
ll a[N+5];
int main() {
    freopen("TRIP.INP","r",stdin);
    freopen("TRIP.OUT","w",stdout);
    cin>>n>>del;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]%=del;
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        ll t=a[i];
        res=min(res,n*t+(n-i)*del);
    }
    cout<<res-sum;
}
