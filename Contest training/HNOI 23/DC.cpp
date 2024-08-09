#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a,b;
map<long long, long long>mp;
long long cur,res;
long long last;
int main() {
    freopen("DC.INP","r",stdin);
    freopen("DC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a>>b;
        mp[a]++;
        mp[b+1]--;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        if (cur==k) res+=i->first-last;
        cur+=i->second;
        if (cur==k) last=i->first;
    }
    cout<<res;
}
