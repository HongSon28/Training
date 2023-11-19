#include<bits/stdc++.h>
using namespace std;
vector<int>v[26];
string str2min(const string &s, int l, int r) {
    if (l == r) {
        return "";
    }
    int pos,c;
    for (int i=0;i<26;i++) {
        pos=upper_bound(v[i].begin(),v[i].end(),r-1)-v[i].begin();
        if (pos==0||v[i][pos-1]>=r||v[i][pos-1]<l) continue;
        pos--;
        c=i;
        break;
    }
    //cout<<l<<' '<<r<<' '<<v[c][pos]<<endl;
    return s[v[c][pos]]+str2min(s,l,v[c][pos])+str2min(s,v[c][pos]+1,r);
}
int main() {
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++) v[s[i]-'a'].push_back(i);
    cout<<str2min(s, 0, s.size());
}
