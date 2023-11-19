#include<bits/stdc++.h>
using namespace std;
string s;
int t,c0,c1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>s;
        c0=c1=0;
        for (auto i:s) {
            if (i=='0') c0++;
            else c1++;
        }
        if (c1==0) {
            cout<<-1<<'\n';
            continue;
        }
        int l=0,r=s.size()-1;
        while (s[l]=='0') {
            l++;
            c0--;
        }
        while (s[r]=='0') {
            r--;
            c0--;
        }
        cout<<c0<<'\n';
    }
}
