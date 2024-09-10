#include<bits/stdc++.h>
using namespace std;
int sub,t;
int mod;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
int mul(int x,int y) {
	long long temp=(long long)x*y;
	temp%=mod;
	return temp;
}
namespace sub12{
	const int N=10000,M=5000;
	vector<vector<int>>c;
	void prep() {
		c.resize(N+1);
		c[1].resize(M+1);
		c[1][1]=c[1][0]=1;
		for (int i=2;i<=N;i++) {
			c[i].resize(N+1);
			c[i][0]=1;
			for (int j=1;j<=min(i,M);j++) {
				c[i][j]=c[i-1][j-1];
				add(c[i][j],c[i-1][j]);
			}
		}
	}
	int C(int k,int n) {
		return c[n][k];
	}
}
const int N=2e6;
vector<int>f,g,inv;
namespace sub3{
	void prep() {
		f.resize(N+1),g.resize(N+1),inv.resize(N+1);
		f[0]=f[1]=g[0]=g[1]=inv[1]=1;
		for (int i=2;i<=N;i++) {
			f[i]=mul(f[i-1],i);
			inv[i]=mod-mul(mod/i,inv[mod%i]);
			g[i]=mul(g[i-1],inv[i]);
		}
	}
	int C(int k,int n) {
		return mul(mul(f[n],g[n-k]),g[k]);
	}
}
namespace sub4{
	int N=1e6;
	void prep() {
		g.resize(N+1),inv.resize(N+1);
		g[0]=g[1]=inv[1]=1;
		for (int i=2;i<=N;i++) {
			inv[i]=mod-mul(mod/i,inv[mod%i]);
			g[i]=mul(g[i-1],inv[i]);
		}
	}
	int C(long long k,long long n) {
		int res=g[k];
		n%=mod;
		if (n<k) return 0;
		for (long long i=0;i<k;i++) res=1ll*res*(n-i)%mod;
		return res;
	}
}
namespace sub5{
	const int N=2e6;
	bool p[N+5];
	vector<int>prime;
	void prep() {
		memset(p,true,sizeof(p));
		p[0]=p[1]=false;
		for (int i=2;i*i<=N;i++) {
			if (p[i])
				for (int j=i*i;j<=N;j+=i) p[j]=false;
		}
		for (int i=2;i<=N;i++)
			if (p[i]) prime.push_back(i);
	}
	long long power(long long x,long long y) {
		long long res=1;
		while (y>0) {
			if (y&1) res=res*x%mod;
			x=x*x%mod;
			y>>=1;
		}
		return res;
	}
	long long cnt(long long n,long long p) {
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
			long long t=cnt(n,p)-cnt(n-k,p)-cnt(k,p);
			res*=power(p,t);
			res%=mod;
		}
		return res;
	}
}
int main() {
	//freopen("walls.inp","r",stdin);
	//freopen("walls.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>sub>>t>>mod;
    if (sub<=2) sub12::prep();
    else if (sub==3) sub3::prep();
    else if (sub==4) sub4::prep();
    else sub5::prep();
    while (t--) {
    	long long n,c;
    	cin>>n>>c;
    	int res;
    	if (sub<=2) res=sub12::C(c,c+n);
    	else if (sub==3) res=sub3::C(c,c+n);
    	else if (sub==4) res=sub4::C(c,c+n);
    	else res=sub5::C(c,c+n);
    	add(res,-1);
    	cout<<res<<' ';
    }
}