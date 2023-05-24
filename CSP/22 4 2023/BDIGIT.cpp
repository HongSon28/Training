#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        vector<ll>v;
        ll n,cnt=0;
        cin>>n;
        n++;
        v.push_back(n);
        ll base=1;
        while (base*2<n) {
            base*=2;
        }
        while (n!=1) {
            if (n>base) cnt++;
            n%=base;
            if (n==0) n=base;
            base/=2;
        }
        cout<<cnt%2<<endl;
    }
}
