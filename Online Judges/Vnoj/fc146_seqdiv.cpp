#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n;
long long a[N+5],sum[N+5],dp[N+5][N+5],mod=1e9+7,res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	dp[1][0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=n;j>=1;j--) {
			dp[j+1][sum[i]%(j+1)]+=dp[j][sum[i]%j];
			dp[j+1][sum[i]%(j+1)]%=mod;
			if (i==n) {
				res+=dp[j][sum[i]%j];
				res%=mod;
			}
		}
	}
	cout<<res;
}