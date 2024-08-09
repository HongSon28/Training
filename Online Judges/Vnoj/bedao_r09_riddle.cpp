#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    vector<pair<int,int>>v;
    cin>>s;
    int n=s.length(),res=0;
    s=' '+s;
    int i=1;
    while (i<n) {
        int l=i;
        int cnt=1;
        while (s[i]==s[i+1]) {
            cnt++;
            i++;
        }
        i++;
        v.push_back(make_pair(l,l+cnt-1));
    }
    for (int i=0;i<v.size();i++) {
        int l=v[i].first,r=v[i].second;
        if (s[l-1]==s[r+1]) res++;
        res+=(r-l+1)-1;
    }
    cout<<res;
}
