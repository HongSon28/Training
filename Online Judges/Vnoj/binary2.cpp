#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k;
long long mod=1e9;
long long dp[N+5],sum[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    dp[0]=1;
    for (int i=1;i<=k;i++) {
    	dp[i]=(dp[i-1]*2)%mod;
    	sum[i]=(sum[i-1]+dp[i])%mod;
    }
    for (int i=k+1;i<=n;i++) {
    	dp[i]=((sum[i-1]-sum[i-k-1])%mod+mod)%mod;
    	sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<dp[n];
}