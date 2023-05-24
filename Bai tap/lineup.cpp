#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
ll n;
ll res=1e18;
pair<ll,ll>p[N+5];
map<ll,ll>mp;
bool check() {
    for (auto i=mp.begin();i!=mp.end();i++)
        if (i->second==0) return false;
    return true;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
        mp[p[i].second]=0;
    }
    sort(p+1,p+1+n);
    ll i=1,j=1;
    while (i<=n&&j<=n) {
        mp[p[j].second]++;
        while (mp[p[i].second]>1) {
            mp[p[i].second]--;
            i++;
        }
        if (check()==true) {
            res=min(res,p[j].first-p[i].first);
        }
        j++;
    }
    cout<<res;
}
