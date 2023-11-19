#include<bits/stdc++.h>
using namespace std;
int n;
map<string,bool>mp;
string s;
int main() {
    freopen("FSTRING.INP","r",stdin);
    freopen("FSTRING.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
        cin>>s;
        mp[s]=true;
    }
    cin>>n;
    while (n--) {
        cin>>s;
        cout<<mp[s]<<'\n';
    }
}
