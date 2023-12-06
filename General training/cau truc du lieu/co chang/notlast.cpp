#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    map<string,int>mp;
    mp["Bessie"]=0;
    mp["Elsie"]=0;
    mp["Daisy"]=0;
    mp["Gertie"]=0;
    mp["Annabelle"]=0;
    mp["Maggie"]=0;
    mp["Henrietta"]=0;
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        int t;
        cin>>t;
        mp[s]+=t;
    }
    int mn=INT_MAX;
    int res=INT_MAX;
    string resn;
    for (auto i=mp.begin();i!=mp.end();i++) {
        mn=min(mn,i->second);
    }
    for (auto i=mp.begin();i!=mp.end();i++) {
        int t=i->second;
        if (t>mn) {
            if (t<res) {
                res=t;
                resn=i->first;
            }
        }
    }
    cout<<resn;
}
