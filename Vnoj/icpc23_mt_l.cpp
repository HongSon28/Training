#include<bits/stdc++.h>
using namespace std;
string s="Welcome Hue University of Sciences";
map<string,int>mp;
stringstream ss(s);
string t;
int main() {
    while (ss>>t) mp[t]++;
    while (cin>>t) mp[t]--;
    for (auto i=mp.begin();i!=mp.end();i++) {
        if (i->second>0) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
