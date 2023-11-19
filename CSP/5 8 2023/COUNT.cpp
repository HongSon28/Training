#include<bits/stdc++.h>
using namespace std;
int t;
long long n,p,q,r;
long long lcm(long long x,long long y) {
    return x*y/__gcd(x,y);
}
int main() {
    freopen("COUNT.INP","r",stdin);
    freopen("COUNT.OUT","w",stdout);
    cin>>t;
    while (t--) {
        cin>>n>>p>>q>>r;
        long long temp=n/lcm(lcm(p,q),r);
        long long res=0;
        res+=n/lcm(p,q)-temp;
        res+=n/lcm(p,r)-temp;
        res+=n/lcm(q,r)-temp;
        cout<<res<<'\n';
    }
}
