#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n;
long long s;
long long a[N+5];
long long res,f[N+5],g[N+5],mod=1e9+7;
long long power(long long x,long long y) {
	long long res=1;
	while (y>0) {
		if (y&1) res=(res*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
void prep() {
	f[0]=1;
	for (int i=1;i<=N;i++) f[i]=f[i-1]*i%mod;
	g[N]=power(f[N],mod-2);
	for (int i=N-1;i>=0;i--) g[i]=g[i+1]*(i+1)%mod;
}
long long C(long long k,long long n) {
	long long ans=1;
	for (long long i=k+1;i<=n;i++) ans=ans*(i%mod)%mod;
	ans=ans*g[n-k]%mod;
	return ans;
}
long long calc(int mask) {
	long long sum=s;
	for (int i=0;i<n;i++) {
		if (mask>>i&1) sum-=a[i]+1;
	}
	if (sum<0) return 0;
	return C(sum,sum+n-1);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>n>>s;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int mask=0;mask<(1<<n);mask++) {
    	long long cur=calc(mask);
    	if (__builtin_popcount(mask)&1) {
    		res-=cur;
    		if (res<0) res+=mod;
    	} else {
    		res+=cur;
    		if (res>=mod) res-=mod;
    	}
    }
    cout<<res;
}