#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e7;
ll calc (ll a,ll b,ll c, ll d) {
    return (c-a)*(c-a)+(d-b)*(d-b);
}
ll fi(ll a1,ll a2,ll b1,ll b2) {
    ll lo=-N,hi=N;
    while (lo<=hi) {
        ll mid=(lo+hi)/2;
        //cout<<lo<<' '<<hi<<' '<<mid<<endl;
        if (a1<=mid&&a2>=mid&&b1<=mid&&b2>=mid) {
            return mid;
        } else if (mid<a1||mid<b1) lo=mid+1;
        else hi=mid-1;
    }
    return -N;
}
int main() {
    freopen("COVERED.INP","r",stdin);
    freopen("COVERED.OUT","w",stdout);
    ll t;
    cin>>t;
    while (t--) {
        ll x1,y1,x2,y2,x3,y3,x4,y4;
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        if (fi(y1,y2,y3,y4)!=-N) {
            ll t=fi(y1,y2,y3,y4);
            cout<<min(calc(x2,t,x3,t),calc(x1,t,x4,t))<<endl;
        } else if (fi(x1,x2,x3,x4)!=-N) {
            ll t=fi(x1,x2,x3,x4);
            cout<<min(calc(y2,t,y3,t),calc(y1,t,y4,t))<<endl;
        } else {
            cout<<min({calc(x2,y2,x3,y3),calc(x1,y1,x4,y4),calc(x1,y2,x4,y3),calc(x2,y1,x3,y4)})<<endl;
        }
    }
}

