#include<bits/stdc++.h>
using namespace std;
int c[26];
string s;
int t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        memset(c,0,sizeof(c));
        bool flag=false;
        cin>>s;
        for (auto i:s) c[i-'a']++;
        for (int i=0;i<s.size();i++) {
            if (c[s[i]-'a']==1) {
                cout<<i+1<<'\n';
                flag=true;
                break;
            }
        }
        if (!flag) cout<<-1<<'\n';
    }
}
