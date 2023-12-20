#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k;
int a[N+5],dp[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		dp[i]=dp[i-1]+a[i];
		for (int j=i-2;j>=max(0,i-k);j--) dp[i]=max(dp[i],dp[j]+a[i]);
		res=max(res,dp[i]);
	}
	cout<<res;
}