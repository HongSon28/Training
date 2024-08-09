#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
int a[N+5];
long long res,dp[N+5][N+5],mod=1e9+7,g[N+5],inv[N+5];
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
long long C(int k,int n) {
	return g[n]*inv[k]%mod*inv[n-k]%mod;
}
long long f(int i,int j) {
	if (i+1>j-1) return 1;
    if (j-i==2) return a[i]!=a[j]||j-i==n;
	if (dp[i][j]!=-1) return dp[i][j];
	long long ans=0;
	for (int k=i+1;k<j;k++) {
		if (a[i]==a[k]||a[k]==a[j]) continue;
		ans+=f(i,k)*f(k,j)%mod*C(k-i-1,j-i-2)%mod;
		//cout<<k-i-1<<' '<<j-i-2<<' '<<C(k-i-1,j-i-2)<<' '<<ans<<endl;
		ans%=mod;
	}
	return dp[i][j]=ans;
}
void readinput() {
	cin>>n;
	g[0]=inv[0]=1;
    for (int i=1;i<=n;i++) {
    	g[i]=(g[i-1]*i)%mod;
		inv[i]=(inv[i-1]*power(i,mod-2))%mod;
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		a[n+i]=a[i];
	}
}
void solve() {
	for (int i=1;i<=n;i++)
        if (a[i]==a[i+1]){
            cout<<0;
            return;
        }
    memset(dp,-1,sizeof(dp));
	for (int i=1;i<=n;i++) {
		res+=f(i,i+n);
		res%=mod;
	}
	cout<<res;
}
int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	readinput();
	solve();
}