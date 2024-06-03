#include<bits/stdc++.h>
using namespace std;
set<char> s[26];
char cc[26];
string st;
int n,m;
int main() {
    freopen("CHGSTR.INP","r",stdin);
    freopen("CHGSTR.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cin>>st;
    for (char x='a';x<='z';x++) s[x-'a'].insert(x);
    while (m--) {
        char x,y;
        cin>>x>>y;
        for (auto c:s[x-'a'])
            s[y-'a'].insert(c);
        s[x-'a'].clear();
    }
    for (char x='a';x<='z';x++) {
        for (auto c:s[x-'a']) cc[c-'a']=x;
    }
    for (auto i:st) cout<<cc[i-'a'];
}
