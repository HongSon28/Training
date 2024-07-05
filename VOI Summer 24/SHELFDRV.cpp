#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,k;
long long mod=1e9+7;
pair<int,int>p[N+5];
long long gt[N+5],inv[N+5],dp[N+5];
long long power(long long a,long long b) {
	long long ans=1;
	while (b) {
		if (b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
void prep() {
	gt[0]=1;
	for (int i=1;i<=N;i++) gt[i]=(gt[i-1]*i)%mod;
	inv[N]=power(gt[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%mod;
}
long long C(long long k,long long n) {
	if (k>n) return 0;
	return (gt[n]*inv[k]%mod)*inv[n-k]%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    prep();
    cin>>m>>n>>k;
    for (int i=1;i<=k;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+k);
    p[k+1]={m,n};
    for (int i=1;i<=k+1;i++) {
    	dp[i]=C(p[i].first-1,p[i].first+p[i].second-2);
    	for (int j=1;j<i;j++) {
    		if(p[j].first>p[i].first||p[j].second>p[i].second) continue;
    		dp[i]-=dp[j]*C(p[i].first-p[j].first,p[i].first-p[j].first+p[i].second-p[j].second)%mod;
    		if (dp[i]<0) dp[i]+=mod;
    	}
    	//cout<<dp[i]<<endl;
    }
    cout<<dp[k+1];
}