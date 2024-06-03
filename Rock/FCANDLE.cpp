#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,q;
long long mod=1e9;
long long dp[N+5],c[N+5][N+5];
long long C(int k,int n) {
	if (c[k][n]!=-1) return c[k][n];
	if (k==0||k==n) return c[k][n]=1;
	if (k>n) return c[k][n]=0;
	return c[k][n]=(C(k-1,n-1)+C(k,n-1))%mod;
}
long long f(int n) {
	if (dp[n]!=-1) return dp[n];
	if (n<=1) return dp[n]=1;
	long long ans=0;
	for (int i=2;i<=n;i+=2) {
		ans+=(f(i-1)*f(n-i)%mod)*C(i-1,n-1)%mod;
		ans%=mod;
	}
	return dp[n]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(dp,-1,sizeof(dp));
    memset(c,-1,sizeof(c));
    cin>>q;
    while (q--) {
    	cin>>n;
    	string s=to_string(f(n));
    	while (s.size()<9) s="0"+s;
    	cout<<s<<'\n';
    }
}