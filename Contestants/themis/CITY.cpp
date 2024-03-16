#include<bits/stdc++.h>
using namespace std;
const int N=4e5,M=1e6;
int n,k;
long long a[N+5],dp[N+5][31],inf=1e18,res;
long long mx[M*2+5][31];
long long best[31];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	dp[i][0]=a[i];
    	for (int j=1;j<=k;j++) dp[i][j]=-inf;
	}
	for (int i=0;i<=M*2;i++)
		for (int j=0;j<=30;j++) mx[i][j]=-inf;
	for (int i=0;i<=k;i++) best[i]=-inf;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			dp[i][j]=max(dp[i][j],mx[a[i]-i+M][j]+a[i]);
			if (j>0) {
				dp[i][j]=max(dp[i][j],best[j-1]+a[i]);
			}
			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
		for (int j=0;j<=k;j++) {
			best[j]=max(best[j],dp[i][j]);
			mx[a[i]-i+M][j]=max(mx[a[i]-i+M][j],dp[i][j]);
		}
	}
	for (int i=0;i<=k;i++) res=max(res,best[i]);
	cout<<res;
}