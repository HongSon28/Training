#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("UCBC.INP","r",stdin);
    freopen("UCBC.OUT","w",stdout);
    int n;
    cin>>n;
    long long a[n+1];
    for (int i=1;i<=n;i++) cin>>a[i];
    long long uc=__gcd(a[1],a[2]);
    for (int i=3;i<=n;i++) uc=__gcd(uc,a[i]);
    long long bc=a[1]*a[2]/__gcd(a[1],a[2]);
    for (int i=3;i<=n;i++) bc=bc*a[i]/__gcd(bc,a[i]);
    cout<<uc<<endl<<bc;
}
