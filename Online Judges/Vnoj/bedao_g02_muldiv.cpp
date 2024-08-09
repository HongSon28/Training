#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int d[N+5];
long long mod=998244353;
void seive() {
	iota(d,d+N+5,0);
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i) {
			for (int j=i*i;j<=N;j+=i)
				if (i<d[j]) d[j]=i;
		}
	}
} 
int t,n,nn;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	seive();
	cin>>t;
	while (t--) {
		cin>>n;
		nn=n;
		int m=1;
		while (n>1) {
			int cnt=0;
			int div=d[n];
			while (n%div==0) {
				n/=div;
				cnt++;
			}
			m*=cnt+1;
		}
		int sq=sqrt(nn);
		if (sq*sq==nn) cout<<sq*power(nn,m/2)%mod<<'\n';
		else cout<<power(nn,m/2)<<'\n';
	}
}