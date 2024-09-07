#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,p;
long long mod1=998244353;
long long mod2=220797;
int n,m,k;
long long f[N+5],inv[N+5],g[N+5];
namespace sub12 {
	long long power(long long x,long long y) {
		long long res=1;
		while (y>0) {
			if (y&1) res=(res*x)%mod1;
			x=(x*x)%mod1;
			y>>=1;
		}
		return res;
	}
	void prep() {
		f[0]=g[0]=f[1]=g[1]=inv[1]=1;
		for (int i=2;i<=N;i++) {
			f[i]=f[i-1]*i%mod1;
			inv[i]=mod1-mod1/i*inv[mod1%i]%mod1;
			g[i]=g[i-1]*inv[i]%mod1;
		}
	}
	long long C(long long k,long long n) {
		return (f[n]*g[n-k]%mod1)*g[k]%mod1;
	}
	void solve() {
		long long res=C(k,n-1)*m%mod1;
		res=res*power(m-1,k)%mod1;
		cout<<res<<'\n';
	}
}
namespace sub3{
	long long power(long long x,long long y) {
		long long res=1;
		while (y>0) {
			if (y&1) res=(res*x)%mod1;
			x=(x*x)%mod1;
			y>>=1;
		}
		return res;
	}
	long long C(long long k,long long n) {
		long long res=g[k];
		for (int i=0;i<k;i++) res=(res*(n-i))%mod1;
		return res;
	}
	void solve() {
		long long res=C(k,n-1)*m%mod1;
		res=res*power(m-1,k)%mod1;
		cout<<res<<'\n';
	}
}
namespace sub4{
	bool p[N+5];
	vector<int>prime;
	long long power(long long x,long long y) {
		long long res=1;
		while (y>0) {
			if (y&1) res=(res*x)%mod2;
			x=(x*x)%mod2;
			y>>=1;
		}
		return res;
	}
	void prep() {
		memset(p,true,sizeof(p));
		p[0]=p[1]=false;
		for (int i=2;i*i<=N;i++) {
			if (p[i]) {
				for (int j=i*i;j<=N;j+=i) p[j]=false;
			}
		}
		for (int i=2;i<=N;i++)
			if (p[i]) prime.push_back(i);
	}
	long long cnt(long long p,long long n) {
		long long res=0;
		long long pw=p;
		while (pw<=n) {
			res+=n/pw;
			pw*=p;
		}
		return res;
	}
	long long C(long long k,long long n) {
		long long res=1;
		if (k>n) return 0;
		for (auto p:prime) {
			long long t=cnt(p,n)-cnt(p,k)-cnt(p,n-k);
			res*=power(p,t);
			res%=mod2;
		}
		return res;
	}
	void solve() {
		long long res=C(k,n-1)*m%mod2;
		res=res*power(m-1,k)%mod2;
		cout<<res<<'\n';
	}
}
int main() {
	freopen("flowers.inp","r",stdin);
	freopen("flowers.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t>>p;
    if (p==mod1) sub12::prep(); 
    else sub4::prep();
    while (t--) {
    	cin>>n>>m>>k;
    	if (p==mod1&&n<=N) sub12::solve();
    	else if (p==mod1&&n>N) sub3::solve();
    	else sub4::solve();
    }
}