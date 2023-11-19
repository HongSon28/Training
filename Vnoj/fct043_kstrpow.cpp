#include<bits/stdc++.h>
using namespace std;
string s,t;
int k;
string temp;
int main() {
    cin>>s>>t;
    cin>>k;
    for (int i=1;i<=k;i++) temp+=s;
    if (temp==t) cout<<"YES";
    else cout<<"NO";
}
