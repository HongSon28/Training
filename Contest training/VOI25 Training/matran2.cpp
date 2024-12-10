#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int n,m;
long long f[N+5],g[N+5],p[N+5],mod=998244353,res;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return (x%mod);
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=(ans*x)%mod;
	return ans;
}
void prep() {
	f[0]=1;
	p[0]=1;
	for (int i=1;i<=N;i++) {
		f[i]=f[i-1]*i%mod;
		p[i]=p[i-1]*2;
		if (p[i]>=mod) p[i]-=mod;
	}
	g[N]=power(f[N],mod-2);
	for (int i=N-1;i>=0;i--) g[i]=g[i+1]*(i+1)%mod;
}
long long C(int k,int n) {
	return (f[n]*g[k]%mod)*g[n-k]%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>n>>m;
    for (int i=0;i<=n;i++) {
    	for (int j=0;j<=m;j++) {
    		long long cur=(C(i,n)*C(j,m)%mod)*p[n*m-m*i-n*j+i*j]%mod;
    		if ((j&1)!=(i&1)) {
    			res-=cur;
    			if (res<0) res+=mod;
    		} else {
    			res+=cur;
    			if (res>=mod) res-=mod;
    		}
    	}
    }
    cout<<res;
}