#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
map<int,int>mp;
int n,t;
int res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t;
        mp[t]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        t=i->second;
        if (t==1) {
            cout<<-1;
            return 0;
        }
        if (t%3==0) res+=t/3;
        else res+=t/3+1;
    }
    cout<<res;
}
