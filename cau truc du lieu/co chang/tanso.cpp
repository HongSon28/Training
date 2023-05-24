#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map <int,int> mp;
    for (int i=0;i<n;i++) {
        int t;
        cin>>t;
        mp[t]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        cout<<i->first<<' '<<i->second<<endl;
    }
}
