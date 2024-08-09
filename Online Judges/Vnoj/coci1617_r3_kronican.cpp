#include<bits/stdc++.h>
using namespace std;
int n,k;
int res=INT_MAX;
int c[22][22];
int dp[1<<22];
vector<int>msk[22];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=0;i<n;i++)
		for (int j=0;j<n ;j++)
			cin>>c[i][j];
	for (int i=0;i<(1<<n);i++) {
		msk[(__builtin_popcount(i))].push_back(i);
		dp[i]=INT_MAX;
	}
	dp[(1<<n)-1]=0;
	for (int t=n;t>k;t--) {
		for (auto mask:msk[t]) {
			for (int i=0;i<n;i++) {
				for (int j=0;j<n;j++) {
					if ((mask>>i&1)&&(mask>>j&1)&&(i!=j)) {
						int newmsk=mask&(~(1<<i));
						dp[newmsk]=min(dp[newmsk],dp[mask]+c[i][j]);
					}
				}
			}
		}
	}
	for (auto mask:msk[k]) res=min(res,dp[mask]);
	cout<<res;
}