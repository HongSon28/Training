#include<bits/stdc++.h>
using namespace std;
int main() {
    int k;
    cin>>k;
    while (k--) {
        int n;
        map<long long, long long>mp;
        cin>>n;
        for (int i=0;i<n;i++) {
            long long t;
            cin>>t;
            mp[t]++;
        }
        long long res=1,cnt1=0,cnt2=0;
        for (auto i=mp.rbegin();i!=mp.rend();i++) {
            if (cnt1==2) break;
            if (i->second>=2) {
                cnt1++;
                res*=i->first;
            }
        }
        for (auto i=mp.rbegin();i!=mp.rend();i++) {
            if (cnt2==1) break;
            if (i->second>=4) {
                cnt2++;
                res=max(res,(i->first)*(i->first));
            }
        }
        if (cnt1==2||cnt2==1) cout<<res<<endl;
        else cout<<-1<<endl;
    }
}
