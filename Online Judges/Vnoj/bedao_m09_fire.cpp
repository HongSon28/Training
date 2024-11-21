#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int a,b,q;
long long g[N+5],inv[N+5],mod=1e9+7;
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=(ans*x)%mod;
	return ans;
}
void prep() {
	g[0]=1;
	for (int i=1;i<=N;i++) g[i]=g[i-1]*i%mod;
	inv[N]=power(g[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(int k,int n) {
	return g[n]*inv[n-k]%mod*inv[k]%mod;
}
long long sum[N+5];
long long get(int l,int r) {
	if (l==0) return sum[r];
	return sum[r]-sum[l-1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	prep();
	cin>>a>>b>>q;
	for (int i=0;i<=min(a,b);i++) {
		if (i>0) sum[i]=sum[i-1];
		sum[i]+=C(i,a)*C(i,b)%mod;
		sum[i]%=mod;
		//cout<<i<<' '<<calc(0,a,i,i)<<' '<<calc(i,i,b,0)<<endl;
	}
	while (q--) {
		int x,t,l,r;
		cin>>x>>t;
		l=max(x-t,0),r=min(x+t,min(a,b));
		if (l>r) cout<<C(a,a+b)<<'\n';
		else cout<<((C(a,a+b)-get(l,r))%mod+mod)%mod<<'\n';
	}
}