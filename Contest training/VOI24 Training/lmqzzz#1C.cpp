#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,m,k;
long long mod=998244353;
long long g[N+5],inv[N+5];
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long res=power(x,y/2);
	res=(res*res)%mod;
	if (y%2==1) res=(res*x)%mod;
	return res;
}
void prep() {
	g[0]=1;
	for (int i=1;i<=N;i++) g[i]=(g[i-1]*i)%mod;
	inv[N]=power(g[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(int k,int n) {
	return g[n]*inv[k]%mod*inv[n-k]%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>t;
    while (t--) {
    	cin>>n>>m>>k;
    	long long res=C(m-1,m+k-1);
    	for (int i=1;i<=m;i++) {
    		k-=n;
    		if (k<0) break;
    		long long cur=C(m-1,m+k-1);
    		cur*=C(i,m);
    		cur%=mod;
    		if (i%2==1) res=((res-cur)%mod+mod)%mod;
    		else res=(res+cur)%mod;
    	}
    	cout<<res<<'\n';
    }
}