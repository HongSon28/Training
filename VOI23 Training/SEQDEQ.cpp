#include<bits/stdc++.h>
using namespace std;
const int N=100,M=1e3;
long long dp[N+5][M+5],sum[N+5][M+5],mod=1e9+7;
int n;
int h[N+5];
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
long long calc(int x) {
	memset(dp,0,sizeof(dp));
	dp[1][0]=sum[1][0]=1;
	for (int i=1;i<=M;i++) {
		if (i<=h[1]-x) dp[1][i]=1;
		else dp[1][i]=0;
		sum[1][i]=sum[1][i-1];
		add(sum[1][i],dp[1][i]);
	}
	for (int i=2;i<=n;i++) {
		for (int j=0;j<=h[i]-x;j++) {
			dp[i][j]=sum[i-1][h[i]-j-x];
		}
		sum[i][0]=dp[i][0]%mod;
		for (int j=1;j<=M;j++) {
			sum[i][j]=sum[i][j-1];
			add(sum[i][j],dp[i][j]);
		}
	}
	return sum[n-1][h[n]-x];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>h[i];
	int mn=1e9;
	for (int i=1;i<=n;i++) mn=min(mn,h[i]);
	if (n%2==0) cout<<calc(0);
	else {
		long long res=0;
		for (int i=0;i<=mn;i++) {
			add(res,calc(i));
		}
		cout<<res;
	}
}