#include<bits/stdc++.h>
using namespace std;
const int N=100003;
int mod=100003;
long long f[N+5],g[N+5];
long long power(long long x,long long y) {
	long long res=1;
	while (y>0) {
		if (y&1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
void prep() {
	f[0]=g[0]=1;
	for (int i=1;i<=N;i++) {
		f[i]=(f[i-1]*i)%mod;
		g[i]=power(f[i],mod-2);
	}
}
long long C(long long k,long long n) {
	if (k<0||k>n) return 0;
	if (k==0||k==n) return 1;
	if (n>=mod) return C(k/mod,n/mod)*C(k%mod,n%mod)%mod;
	return f[n]*g[k]%mod*g[n-k]%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    int t;
    long long n,m;
    cin>>t;
    while (t--) {
    	cin>>m>>n;
    	cout<<C(n,m-n+1)<<'\n';
    }
}