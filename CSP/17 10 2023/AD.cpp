#include<bits/stdc++.h>
using namespace std;
int c[26];
string a,b;
int res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("AD.INP","r",stdin);
    freopen("AD.OUT","w",stdout);
    cin>>a>>b;
    for (auto i:a) c[i-'a']++;
    for (auto i:b) c[i-'a']--;
    for (int i=0;i<26;i++) res+=abs(c[i]);
    cout<<res;
}
