#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long dp[N+5],dq[N+5],sum[N+5],a[101],mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0]=1;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=k;j++) {
    		dp[j]+=dp[j-1];
    		dp[j]%=mod;
    	} 
    	for (int j=0;j<=k;j++) {
    		if (j>a[i]) dq[j]=dp[j]-dp[j-a[i]-1];
    		else dq[j]=dp[j];
    		dq[j]=(dq[j]%mod+mod)%mod;
    	}
    	for (int j=0;j<=k;j++) swap(dp[j],dq[j]);
    }
    cout<<dp[k];
}