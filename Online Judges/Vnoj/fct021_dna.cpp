#include<bits/stdc++.h>
using namespace std;
string s;
int n;
string t;
int main() {
    cin>>s;
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>t;
        if (s.size()!=t.size()) continue;
        int cnt=0;
        for (int i=0;i<s.size();i++)
            if (s[i]!=t[i]) cnt++;
        if (cnt<=2) cout<<i<<' ';
    }
}
