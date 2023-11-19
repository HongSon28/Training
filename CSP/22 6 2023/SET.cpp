#include<bits/stdc++.h>
using namespace std;
int t;
int k,a,b;
int m;
int p,q;
int main() {
    freopen("SET.INP","r",stdin);
    freopen("SET.OUT","w",stdout);
    cin>>t;
    while (t--) {
        cin>>k>>a>>b>>m;
        b-=a;
        while (__gcd(b,k)!=1) b/=__gcd(b,k);
        while (m--) {
            cin>>p>>q;
            if (p==q) cout<<"NO"<<endl;
            else if (p<q&&k>0) {
                if ((q-p)%b==0) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            } else if (p>q&&k<0) {
                if ((q-p)%b==0) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            } else cout<<"NO"<<endl;
        }
    }
}
