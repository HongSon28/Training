#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,n;
    cin>>a>>n;
    string s=to_string(a);
    while (n>s.size()) {
        n-=s.size();
        a+=2;
        s=to_string(a);
        cout<<n<<' ';
    }
    cout<<s[n-1];
}
