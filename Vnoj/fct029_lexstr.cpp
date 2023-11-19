#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int f[26];
string res;
int main() {
    cin>>n>>s;
    for (int i=0;i<26;i++) cin>>f[i];
    for (auto i:s) {
        if (i=='?') continue;
        f[i-'a']--;
        if (f[i-'a']<0) {
            cout<<-1;
            return 0;
        }
    }
    for (auto i:s) {
        if (i!='?') {
            res+=i;
            continue;
        }
        bool c=false;
        for (int j=0;j<26;j++) {
            if (f[j]>0) {
                f[j]--;
                res+=(char)(j+'a');
                c=true;
                break;
            }
        }
        if (!c) {
            cout<<-1;
            return 0;
        }
    }
    cout<<res;
}
