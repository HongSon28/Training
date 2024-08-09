#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r,cur,res,cnt,last;
map<long long,long long>mp;
int main() {
    freopen("DONGXU.INP","r",stdin);
    freopen("DONGXU.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    while (m--) {
        cin>>l>>r;
        if (l<=r) {
            mp[l]++;
            mp[r+1]--;
        } else {
            mp[l]++;
            mp[n+1]--;
            mp[1]++;
            mp[r+1]--;
        }
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        if (cur==res) cnt+=(i->first)-last;
        //cout<<i->first<<' '<<i->second<<endl;
        cur+=i->second;
        if (cur>res) {
            res=cur;
            cnt=0;
        }
        if (cur==res) last=i->first;
    }
    cout<<res<<' '<<cnt;
}
