#include<bits/stdc++.h>
using namespace std;
int n,m;
int main() {
    cin>>n>>m;
    string a,b;
    for (int i=1;i<=n;i++) a+=to_string(m);
    for (int i=1;i<=m;i++) b+=to_string(n);
    if (a<b) cout<<a;
    else cout<<b;
}
