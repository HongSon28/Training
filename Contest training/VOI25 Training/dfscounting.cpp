#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int k,m;
long long dp[N+5],sum[N+5],mod=998244353;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k>>m;
	dp[k]=1,sum[k]=1;
	for (int i=k+1;i<=N;i++) {
		dp[i]=sum[i-1]-sum[i-k];
		dp[i]=(dp[i]%mod+mod)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	long long res=1;
	for (int i=1;i<=m;i++) {
		int t;
		cin>>t;
		res=(res*dp[t])%mod;
	}
	cout<<res;
}