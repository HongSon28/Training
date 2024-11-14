#include<bits/stdc++.h>
using namespace std;
int q;
long long n,m,sq;
set<long long>s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>q;
    while (q--) {
        cin>>n;
        s.clear();
        for (long long k=1;k*k*k<=n;k++) {
            if (n%k!=0) continue;
            m=n/k;
            sq=sqrt(m);
            if (sq*(sq+1)==m) s.insert(sq);
        }
        for (long long x=1;x*x*x<=n;x++) {
            m=x*x+x;
            if (n%m==0) s.insert(x);
        }
        if (s.empty()) cout<<-1;
        else for (auto i:s) cout<<i<<' ';
        cout<<'\n';
    }
}
