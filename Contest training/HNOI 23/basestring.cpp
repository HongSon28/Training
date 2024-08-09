#include<bits/stdc++.h>
using namespace std;
string s,t;
int main() {
    cin>>s>>t;
    if (s+t!=t+s) {
        cout<<"NO";
        return 0;
    }
    cout<<s.substr(0,__gcd(s.size(),t.size()));
}
