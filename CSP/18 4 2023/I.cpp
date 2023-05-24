#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    freopen("I.INP","r",stdin);
    freopen("I.OUT","w",stdout);
    int t;
    cin>>t;
    while (t--) {
        ll res=0;
        map<ll,ll>mp;
        mp[0]=1;
        ll d,n;
        cin>>d>>n;
        ll sum=0;
        for (int i=1;i<=n;i++) {
            ll temp;
            cin>>temp;
            sum+=temp;
            sum=(sum%d+d)%d;
            res+=mp[sum];
            mp[sum]++;
        }
        cout<<res<<endl;
    }
}
