#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long a,b,k,mod=1e9+7,g[N+5],res;
void pre() {
	g[1]=1;
	g[0]=1;
	for (long long i=2;i<=N;i++) g[i]=g[i-1]*i%mod;
}
long long power(long long x, long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
long long divi(long long x,long long y) {
	return (x*power(y,mod-2))%mod;
}
long long C(long long k,long long n) {
	if (k>n) return 0;
	return divi(g[n],g[n-k]*g[k]%mod);
}
long long P(long long k,long long n) {
	if (k>n) return 0;
	return divi(g[n],g[n-k]);
}
long long calc(long long t) {
	long long cnt=0;
	long long tt=t;
	for (long long div=2;div*div<=tt;div++) {
		while (t%div==0) {
			t/=div;
			cnt++;
		}
		if (t==1) break;
	}
	if (t!=1) cnt++;
	//cout<<k-1<<' '<<cnt<<' '<<cnt+k-1<<' '<<C(k-1,cnt+k-1)<<endl;
	return C(k-1,cnt+k-1);
}
long long calc2(int t) {
	if (t==1) return 1;
	if (t==2||t==3||t==5||t==7) return k;
	if (t==4||t==9) return (C(2,k)+k)%mod;
	if (t==6) return P(2,k);
	return (C(3,k)+P(2,k)+k)%mod;
}
void solve() {
	pre();
	for (int x=1;x<=a;x++) {
		if (b%x!=0) continue;
		int y=b/x;
		res+=calc2(x)*calc2(y)%mod;
		//cout<<x<<' '<<y<<' '<<calc2(x)<<' '<<calc2(y)<<endl;
    	res%=mod;
	}
	cout<<res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b>>k;
    if (a<=10&&b<=10&&k<=10) {
    	solve();
    	return 0;
    }
    pre();
    for (long long x=1;x<=a&&x*x<=b;x++) {
    	if (b%x!=0) continue;
    	res+=calc(x)*calc(b/x)%mod;
    	res%=mod;
    	//cout<<x<<' '<<calc(x)<<' '<<b/x<<' '<<calc(b/x)<<endl;
		long long y=b/x;
		if (y<=a&&y!=x) {
			//cout<<y<<' '<<calc(y)<<' '<<b/y<<' '<<calc(b/y)<<endl;
			res+=calc(y)*calc(b/y)%mod;
    		res%=mod;
		}
    }
    cout<<res;
}