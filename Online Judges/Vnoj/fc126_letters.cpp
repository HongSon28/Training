#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int main() {
    cin>>n>>s;
    if (s[0]=='?') s[0]='a';
    if (s[n-1]=='?') s[n-1]='b';
    cout<<s[n-1]-s[0];
}
