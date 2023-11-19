#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m,k;
long long cnt[N+5];
long long mod=998244353;
long long power(long long x,long long n) {
    if (n==1) return x%mod;
    long long temp=power(x,n/2);
    temp=temp*temp%mod;
    if (n%2==1) temp*=x;
    return temp%mod;
}
int main() {
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) cnt[i]=power(m/i,n);
    for (int i=m;i>=k;i--) {
        for (int j=i*2;j<=m;j+=i) {
            cnt[i]-=cnt[j];
            cnt[i]=(cnt[i]%mod+mod)%mod;
        }
    }
    cout<<cnt[k];
}
