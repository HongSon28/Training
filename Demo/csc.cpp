#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int n=s.length();
    for (int i=0;i<n;i++) {
        if (s[i]>='A'&&s[i]<='Z') {
            s[i]+=32;
        }
    }
    map<char,int> mp;
    for (int i=0;i<n;i++) {
        mp[s[i]]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++) {
        if(i->first!=' ')
            cout<<i->first<<" "<<i->second<<endl;
    }
}
