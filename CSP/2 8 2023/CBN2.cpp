#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long mod=1e9+7;
long long ex[N+5];
long long n,k;
long long power(long long x, long long n) {
    long long temp;
    if (n==0) return 1;
    temp=power(x,n/2)%mod;
    if (n%2==0) {
        long long res=temp*temp;
        res%=mod;
        return res;
    } else {
        long long res=((x%mod)*temp)%mod*temp;
        res%=mod;
        return res;
    }
}
long long cbn(long long k, long long n) {
    return (ex[n]%mod)*power((ex[k]%mod)*(ex[n-k]%mod)%mod,mod-2)%mod;
}
int main() {
    freopen("CBN2.INP","r",stdin);
    freopen("CBN2.OUT","w",stdout);
    ex[1]=1;
    for (int i=2;i<=N;i++) ex[i]=ex[i-1]*i%mod;
    cin>>n>>k;
    cout<<cbn(k-1,n+k-1);
}
