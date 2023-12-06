#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long res=0;
    cin>>n;
    string s;
    cin>>s;
    long long dem1=0,dem2=0;
    for (int i=n;i>=0;i--) {
        if (s[i]=='W') {
            dem1++;
        } else if (s[i]=='O') {
            dem2+=dem1;
        } else {
            res+=dem2;
        }
    }
    cout<<res;
}
