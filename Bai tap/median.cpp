#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll seed,mul,add,n,k,res=0;
    cin>>seed>>mul>>add>>n>>k;
    multiset<pair<ll,ll>>l,r;
    ll a[n+5];
    a[1]=seed;
    for (int i=2;i<=n;i++) a[i]=(a[i-1]*mul+add)%65536;
    for (int i=1;i<k;i++) l.insert(make_pair(a[i],i));
    for (int i=k;i<=n;i++) {
        if (!l.empty()&&((*l.rbegin()).first>=a[i])) l.insert(make_pair(a[i],i));
        else r.insert(make_pair(a[i],i));
        while (l.size()<r.size()) {
            ll x=(*r.begin()).second;
            r.erase(make_pair(a[x],x));
            l.insert(make_pair(a[x],x));
        }
        while (l.size()>r.size()+1) {
            ll x=(*l.rbegin()).second;
            l.erase(make_pair(a[x],x));
            r.insert(make_pair(a[x],x));
        }
        res+=(*l.rbegin()).first;
        if (r.find(make_pair(a[i+1-k],i+1-k))!=r.end())
            r.erase(make_pair(a[i+1-k],i+1-k));
        else l.erase((make_pair(a[i+1-k],i+1-k)));
    }
    cout<<res;
}
