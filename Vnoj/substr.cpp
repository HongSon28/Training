#include<bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    string t=a.substr(0,m);
    if (t==b) cout<<1<<' ';
    for (int i=1;i<=n-m;i++) {
        t.erase(0,1);
        t+=a[i+m-1];
        if (t==b) cout<<i+1<<' ';
    }
}
