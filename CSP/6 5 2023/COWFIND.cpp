#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("COWFIND.INP","r",stdin);
    freopen("COWFIND.OUT","w",stdout);
    string s;
    cin>>s;
    long long cnt1=0,res=0;
    for (int i=0;i<s.size()-1;i++) {
        if (s[i]=='('&&s[i+1]=='(') {
            cnt1++;
        } else if (s[i]==')'&&s[i+1]==')') {
            res+=cnt1;
        }
    }
    cout<<res;
}
