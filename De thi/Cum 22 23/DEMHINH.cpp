#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("DEMHINH.INP","r",stdin);
    freopen("DEMHINH.OUT","w",stdout);
    int n;
    cin>>n;
    long long res=0;
    map<long long, long long>mp;
    for (int i=0;i<n;i++) {
        long long temp;
        cin>>temp;
        mp[temp]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        res+=(i->second)/4;
    }
    cout<<res;
}
