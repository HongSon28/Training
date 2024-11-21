#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long mod=1e9+7;
int n;
long long g[N+5],inv[N+5];
long long dp[N+5],res;
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=(ans*x)%mod;
	return ans;
}
void prep() {
	g[0]=1;
	for (int i=1;i<=N;i++) g[i]=(g[i-1]*i)%mod;
	inv[N]=power(g[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
long long P(int k,int n) {
	return g[n]*inv[n-k]%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    prep();
    res=n*g[n]%mod;
    for (int i=1;i<=n;i++) {
    	for (int x=n/i;x>=1;x--) {
    		dp[x]=P(i,n/x);
    		for (int y=x*2;y<=n/i;y+=x) {
    			dp[x]-=dp[y];
    			if (dp[x]<0) dp[x]+=mod;
    		}
    		long long temp=dp[x]*(n/x-i)%mod*g[n-i-1]%mod;
    		res-=temp;
    		if (res<0) res+=mod;
    	}
    	for (int x=n/i;x>=1;x--) dp[x]=0;
    } 
    cout<<res;
}