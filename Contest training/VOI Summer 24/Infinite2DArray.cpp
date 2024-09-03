#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long mod=1e9+7;
long long f[N+5],g[N+5],fibo[N+5],inv[N+5];
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
	f[0]=g[0]=f[1]=g[1]=inv[1]=1;
	fibo[1]=1;
	for (int i=2;i<=N;i++) {
		fibo[i]=(fibo[i-1]+fibo[i-2])%mod;
		f[i]=(f[i-1]*i)%mod;
		inv[i]=mod-mod/i*inv[mod%i]%mod;
		g[i]=g[i-1]*inv[i]%mod;
	}
}
long long C(int k,int n) {
	if (k<0||k>n) return 0;
	return (((f[n]*g[k])%mod)*g[n-k])%mod;
}
long long res=0;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    int x,y;
    cin>>x>>y;
    if (x==0||y==0) {
    	cout<<fibo[x+y];
    	return 0;
    }
    for (int i=0;i<=y;i++) {
    	res+=C(x-1,x-1+i)*fibo[y-i]%mod;
    	res%=mod;
    }
    for (int i=0;i<=x;i++) {
    	res+=C(i,y-1+i)*fibo[x-i]%mod;
    	res%=mod;
    }
    cout<<res;
}
