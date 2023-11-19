#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long x[N+5],y[N+5];
long long res;
int main() {
    freopen("TREES.INP","r",stdin);
    freopen("TREES.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<n;i++) {
        long long a=abs(x[i]-x[i+1]);
        long long b=abs(y[i]-y[i+1]);
        res+=__gcd(a,b)+1;
    }
    long long a=abs(x[1]-x[n]);
    long long b=abs(y[1]-y[n]);
    res+=__gcd(a,b)+1;
    cout<<res-n;
}
