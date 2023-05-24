#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ll t;
    cin>>t;
    while (t--) {
        ll a,b;
        cin>>a>>b;
        ll res=0;
        for (ll i=a;i<=b;i++) {
            ll temp=i;
            while (temp>0) {
                res+=temp%10;
                temp/=10;
            }
            res%=9;
        }
        cout<<res<<endl;
    }
}
