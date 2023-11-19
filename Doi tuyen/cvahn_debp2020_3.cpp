#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long n,p,k;
long long a[N+5],sum[N+5],mod=1e9+7;
int main() {
    cin>>n>>k>>p;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=(sum[i-1]+a[i])%mod;
    }
    p%=n;
    long long cnt=k/n;
    k%=n;
    if (p==0) p=n;
    int en=p+k-1;
    if (en>n) {
        en-=n;
        long long res=sum[n]-sum[p-1];
        res=(res+mod)%mod;
        res+=sum[en];
        res%=mod;
        res+=(cnt*sum[n])%mod;
        res%=mod;
        cout<<res;
    } else {
        long long res=sum[en]-sum[p-1];
        res=(res+mod)%mod;
        res+=(cnt*sum[n])%mod;
        res%=mod;
        cout<<res;
    }
}
