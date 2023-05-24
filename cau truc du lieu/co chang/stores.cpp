#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<int,int>mp1,mp2;
    vector<int>v;
    int cb=0,cn=0;
    for (int i=0;i<n;i++) {
        int t;
        string s;
        cin>>t>>s;
        int dif=cb-cn;
        if (mp2.count(dif)==0) {
            mp2[dif]=t;
        }
        if (s=="B") {
            cb++;
        } else {
            cn++;
        }
        dif=cb-cn;
        mp1[t]=dif;

    }
    int res=0;
    for (auto i=++mp1.begin();i!=mp1.end();i++) {
        int f=i->first, s=i->second;
        auto it=mp2.find(s);
        res=max(f-it->second,res);
    }
    cout<<res;
}
