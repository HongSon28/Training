#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long mod=1e9+7;
long long ex[N+5],cal[N+5];
long long n,m,t;
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
    //freopen("CLASSROOM.INP","r",stdin);
    //freopen("CLASSROOM.OUT","w",stdout);
    ex[1]=1;
    cal[1]=1;
    for (int i=2;i<=N;i++) {
        ex[i]=ex[i-1]*i%mod;
        cal[i]=cal[i-1]*ex[i]%mod;
    }
    cin>>t;
    while (t--) {
        cin>>m>>n;
        long long ts=ex[n]*n%mod;
        long long ms=cal[m]*(power(cal[n-1]*cal[n-m-1]%mod,mod-2)%mod)%mod;
        cout<<cal[n-1]<<' '<<cal[n-m-1]<<' '<<cal[n-1]*cal[n-m-1]<<endl;
        cout<<ts<<' '<<ms<<' '<<power(ts*ms%mod,mod-2)%mod<<'\n';
    }
}

