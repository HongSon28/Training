#include<bits/stdc++.h>
using namespace std;
const int N=2e6,M=5e3;
int n,k;
int a[M+5];
long long g[N+5],inv[N+5],mod=1e9+7,res;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=ans*x%mod;
	return ans;
}
void prep() {
	g[0]=1;
	for (int i=1;i<=N;i++) g[i]=g[i-1]*i%mod;
	inv[N]=power(g[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(int k,int n) {
	return g[n]*inv[k]%mod*inv[n-k]%mod;
}
long long calc(int t) {
	long long ans=C(t,k);
	for (int i=1;i<=n;i++) {
		ans*=C(k-t-1,a[i]+k-t-1);
		ans%=mod;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=0;i<=k;i++) {
    	if (i%2==0) res+=calc(i);
    	else res-=calc(i);
    	res=(res%mod+mod)%mod;
    }
    cout<<res;
}