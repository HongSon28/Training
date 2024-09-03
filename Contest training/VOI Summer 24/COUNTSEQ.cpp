#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,s;
int d[N+5];
int fac[N+5];
long long mod=1e9+7;
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
void factor(int x) {
	int id=x;
	while (x>1) {
		int div=d[x];
		int cnt=0;
		while (x%div==0) {
			x/=div;
			cnt++;
		}
		if (cnt>1) {
			fac[id]=-1;
			return;
		}
		fac[id]++;
	}
}
void prep() {
	f[0]=g[0]=1;
	for (int i=1;i<=N;i++) {
		d[i]=i;
		f[i]=(f[i-1]*i)%mod;
		g[i]=power(f[i],mod-2);
	}
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i)
			for (int j=i*i;j<=N;j+=i)
				if (d[j]>i) d[j]=i;
	}
	for (int i=2;i<=N;i++) factor(i);
}
long long C(int k,int n) {
	if (k>n) return 0;
	return (((f[n]*g[k])%mod)*g[n-k])%mod;
}
void add(long long &x, const long long &y) {
	x+=y;
	if (x>=mod) x-=mod;
	if (x<0) x+=mod;
}
long long calc(int k) {
	if (fac[k]==-1) return 0;
	long long temp=C(n-1,s/k-1);
	if (fac[k]&1) return -temp;
	return temp;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>t;
    while (t--) {
    	cin>>s>>n;
    	long long res=C(n-1,s-1);
    	for (int i=2;i*i<=s;i++) {
    		if (s%i!=0) continue;
    		add(res,calc(i));
    		//cout<<i<<' '<<fac[i]<<' '<<calc(i)<<endl;
    		if (s/i!=i) {
    			add(res,calc(s/i));
    			//cout<<s/i<<' '<<fac[s/i]<<' '<<calc(s/i)<<endl;
    		}
    	}
    	add(res,calc(s));
    	//cout<<s<<' '<<fac[s]<<' '<<calc(s)<<endl;
    	cout<<res<<'\n';
    }
}