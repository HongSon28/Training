#include<bits/stdc++.h>
using namespace std;
const int N=5e6,LG=23;
int n,m,k;
long long res,mod=998244353,g[N+5],f[N+5],fac[N+5],ifac[N+5];
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
long long P(int k,int n) {
	if (k>n) return 0;
	return (fac[n]*ifac[n-k])%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k>>m;
    fac[0]=1;
    for (int i=1;i<=N;i++) fac[i]=(fac[i-1]*i)%mod;
    ifac[N]=power(fac[N],mod-2);
    for (int i=N-1;i>=0;i--) ifac[i]=(ifac[i+1]*(i+1))%mod;
    for(int i=1;i<=m;i++) f[i]=1;
	for(int i=0;i<LG;i++){
		for(int j=0;j<=m;j++){
			if(!(j>>i&1)&&(j+(1<<i))<=m){
				f[j]=(f[j]+(f[j+(1<<i)]))%mod;
			}
		}
	}
	for(int i=0;i<=m;i++) g[i]=P(n,f[i]);
	for(int i=0;i<LG;i++){
		for(int j=0;j<=m;j++){
			if(!(j>>i&1)&&(j+(1<<i))<=m){
				g[j]=(g[j]-g[j+(1<<i)]+mod)%mod;
			}
		}
	}
	long long res=0;
	for(int i=0;i<=m;i++){
		if(__builtin_popcount(i)>=k) res=(res+g[i])%mod;
	}
	cout<<res;
}