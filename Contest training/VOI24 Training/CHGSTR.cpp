#include<bits/stdc++.h>
using namespace std;
char c[26];
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
    for (char x='a';x<='z';x++) c[x-'a']=x;
    while (m--) {
        char x,y;
        cin>>x>>y;
        for (int i=0;i<26;i++) {
            if (c[i]==x) c[i]=y;
        }
    }
    for (auto i:st) cout<<c[i-'a'];
}
