#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int d[N+5];
long long mod=1e9+7;
long long f[N+5],g[N+5];
vector<int>e;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long temp=power(x,y/2);
	temp=temp*temp%mod;
	if (y%2==1) temp=temp*x%mod;
	return temp;
}
void prep() {
	f[0]=g[0]=1;
	for (int i=1;i<=N;i++) {
		f[i]=(f[i-1]*i)%mod;
		g[i]=power(f[i],mod-2);
		d[i]=i;
	}
	for (int i=2;i*i<=N;i++) {
		if (i==d[i]) 
			for (int j=i*i;j<=N;j+=i)
				if (d[j]>i) d[j]=i;
	}
}
long long C(int k,int n) {
	//cout<<k<<' '<<n<<' '<<f[n]<<' '<<g[k]<<' '<<g[n-k]<<endl;
	return (f[n]*g[k]%mod)*g[n-k]%mod;
}
long long solve(int x,int y) {
	e.clear();
	while (x>1) {
		int div=d[x],cnt=0;
		while (x%div==0) {
			x/=div;
			cnt++;
		}
		e.emplace_back(cnt);
	}
	long long res=1;
	for (auto ex:e) {
		res*=C(ex,y+ex-1);
		//cout<<ex<<' '<<y+ex-1<<' '<<C(ex,y+ex-1)<<endl;
		res%=mod;
	}
	res*=power(2,y-1);
	return res%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();	
    int t,x,y;
    cin>>t;
    while (t--) {
    	cin>>x>>y;
    	cout<<solve(x,y)<<'\n';
    }
}