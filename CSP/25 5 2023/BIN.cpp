#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int s[N+5];
int findset(int x) {
    if (s[x]==x) return x;
    return findset(s[x]);
}
int main() {
    freopen("BIN.INP","r",stdin);
    freopen("BIN.OUT","w",stdout);
    iota(s,s+N,0);
    int P;
    cin>>P;
    while (P--) {
        int x,y,z;
        cin>>x>>y>>z;
        if (z==1) {
            s[findset(x)]=findset(y);
        } else {
            if (findset(x)==findset(y)) cout<<1<<endl;
            else cout<<0<<endl;
        }
    }
}
