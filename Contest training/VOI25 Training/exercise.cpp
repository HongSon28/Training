#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int rmq[N+5][18];
long long dp[N+5],sum[N+5],mod=1e9+7;
int get(int l,int r) {
	int lg=__lg(r-l+1);
	return max(rmq[l][lg],rmq[r-(1<<lg)+1][lg]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	rmq[i][0]=a[i];
    }
    for (int j=1;(1<<j)<=n;j++) {
    	for (int i=1;i+(1<<j)-1<=n;i++) rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
    }
    dp[0]=sum[0]=1;
    for (int i=1;i<=n;i++) {
    	int lo=2,hi=i,ans=1;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (get(mid,i)>=get(1,mid-1)) {
    			ans=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	dp[i]=sum[ans-1];
    	sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<dp[n];
}