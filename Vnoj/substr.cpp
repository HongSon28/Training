#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long base=311;
long long mod=1e9+7;
long long hash_a[N+5],hash_b[N+5],po[N+5];
int main() {
    string a,b;
    cin>>a>>b;
    int n=a.length(),m=b.length();
    a=' '+a;
    b=' '+b;
    hash_a[0]=hash_b[0]=0;
    po[0]=1;
    for (int i=1;i<=n;i++) hash_a[i]=(hash_a[i-1]*base+a[i]-'0'+1)%mod;
    for (int i=1;i<=m;i++) hash_b[i]=(hash_b[i-1]*base+b[i]-'0'+1)%mod;
    for (int i=1;i<=n;i++) po[i]=po[i-1]*base%mod;
    for (int i=1;i<=n-m+1;i++) {
        int l=i,r=l+m-1;
        long long temp=((hash_a[r]-hash_a[l-1]*po[r-l+1])%mod+mod)%mod;
        if (temp==hash_b[m]) cout<<i<<' ';
    }
}
