#include<bits/stdc++.h>
using namespace std;
string s,t;
int k;
string a;
int main() {
    cin>>s>>t>>k;
    for (int i=1;i<=k;i++) a+=s;
    if (a==t) cout<<"YES";
    else cout<<"NO";
}
