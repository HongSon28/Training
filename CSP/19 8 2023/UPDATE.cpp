#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long s[N+5];
long long a[N+5];
int main() {
    freopen("UPDATE.INP","r",stdin);
    freopen("UPDATE.OUT","w",stdout);
    cin>>n>>q;
    while (q--) {
        long long l,r,v;
        cin>>l>>r>>v;
        s[l]+=v;
        s[r+1]-=v;
    }
    for (int i=1;i<=n;i++) {
        a[i]=a[i-1]+s[i];
        cout<<a[i]<<' ';
    }
}
