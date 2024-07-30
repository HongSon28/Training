#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int t,n;
pair<long long,long long>p[N+5];
bool comp(pair<long long,long long>x,pair<long long,long long>y) {
	if (x.second!=y.second) return x.second>y.second;
	return x.first>y.first;
}
long long dp[N+5][N+5],inf=1e18;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>p[i].first;
		for (int i=1;i<=n;i++) cin>>p[i].second;
		sort(p+1,p+1+n,comp);
		for (int i=1;i<=n;i++) {
			dp[i][0]=0;
			for (int j=1;j<=n;j++)
				dp[i][j]=-inf;
		}
		dp[1][1]=p[1].first;
		for (int i=2;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+p[i].first+p[i].second*(j-1));
			}
		}
		for (int i=1;i<=n;i++) cout<<dp[n][i]<<' ';
		cout<<'\n';
	}
}