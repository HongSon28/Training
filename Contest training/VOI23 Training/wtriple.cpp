#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m,q;
long long a[N+5],b[N+5],c[N+5],sa[N+5],sb[N+5],sc[N+5],mod=1e9+7;
long long res,sum1,sum2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=m;i++) cin>>b[i];
	for (int i=1;i<=q;i++) cin>>c[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	sort(c+1,c+1+q);
	for (int i=1;i<=n;i++) {
		sa[i]=sa[i-1]+a[i];
		sa[i]%=mod;
	}
	for (int i=1;i<=m;i++) {
		sb[i]=sb[i-1]+b[i];
		sb[i]%=mod;
	}
	for (int i=1;i<=q;i++) {
		sc[i]=sc[i-1]+c[i];
		sc[i]%=mod;
	}
	long long l=1,r=1;
	for (int i=1;i<=m;i++) {
		while (a[l]<=b[i]&&l<=n) l++;
		while (c[r]<=b[i]&&r<=q) r++;
		l--;
		r--;
		long long s1=((sa[l]*r)%mod+(sc[r]*l)%mod)%mod;
		long long s2=(sa[l]*sc[r])%mod;
		long long temp=(((((b[i]*b[i])%mod)*((l*r)%mod))%mod+(b[i]*s1)%mod)%mod+s2)%mod;
		res+=temp;
		res%=mod;
		//cout<<i<<' '<<l<<' '<<r<<' '<<temp<<endl;
	}
	cout<<res;
}