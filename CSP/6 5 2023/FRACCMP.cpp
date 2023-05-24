#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cmpint(ll x, ll y) {
    if (x<y) return -1;
    else if (x==y) return 0;
    return 1;
}
int cmp(ll a, ll b, ll c, ll d) {
    ll p=a/b,q=c/d;
    if (p!=q) return cmpint(p,q);
    a%=b,c%=d;
    if (a==0||c==0) return cmpint(a,c);
    return -cmp(b,a,d,c);
}
int main() {
    freopen("FRACCMP.INP","r",stdin);
    freopen("FRACCMP.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<cmp(a,b,c,d)<<endl;
    }
}
