#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int main() {
    freopen("B.inp","r",stdin);
    freopen("B.out","w",stdout);
    cin>>n>>m;
    if (n>=m) cout<<0;
    else {
        ll mul=1;
        for (ll i=1;i<=n;i++) {
            mul*=i;
            mul%=m;
        }
        cout<<mul%m;
    }
}
