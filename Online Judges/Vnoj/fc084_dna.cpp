#include<bits/stdc++.h>
using namespace std;
string s;
int n;
const int N=10;
string t;
int main() {
    cin>>s>>n;
    for (int i=1;i<=n;i++) {
        cin>>t;
        int cnt=0;
        if (s.size()!=t.size()) continue;
        for (int j=0;j<s.size();j++) {
            if (s[j]!=t[j]) {
                cnt++;
            }
        }
        if (cnt<=2) cout<<i<<' ';
    }
}
