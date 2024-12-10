#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
long long f[N+5],g[N+5],mod=1e9+7;
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
long long C(int k,int n) {
	return f[n]*g[k]%mod*g[n-k]%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    int n,m;
    cin>>n>>m;
    cout<<C(m,n+m-1);
}