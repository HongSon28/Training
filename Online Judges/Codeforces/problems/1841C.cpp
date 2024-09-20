#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
string s;
long long dp[N+5][6][2],inf=1e18;
long long v[6];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	v[1]=1;
	v[2]=10;
	v[3]=100;
	v[4]=1000;
	v[5]=10000;
	while (t--) {
		cin>>s;
		n=s.size();
		reverse(s.begin(),s.end());
		s=' '+s;
		for (int i=0;i<=n;i++)
			for (int j=1;j<=5;j++)
				dp[i][j][0]=dp[i][j][1]=-inf;
		dp[0][1][0]=0;
		for (int i=1;i<=n;i++) {
			int val=s[i]-'A'+1;
			for (int j=1;j<=val;j++) {
				dp[i][val][0]=max(dp[i][val][0],dp[i-1][j][0]+v[val]);
				dp[i][val][1]=max(dp[i][val][1],dp[i-1][j][1]+v[val]);
			}
			for (int j=val+1;j<=5;j++) {
				dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]-v[val]);
				dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][1]-v[val]);
			}
			for (int j=1;j<=5;j++) {
				for (int k=j;k<=5;k++) 
					dp[i][k][1]=max(dp[i][k][1],dp[i-1][j][0]+v[k]);
				for (int k=1;k<j;k++) 
					dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][0]-v[k]);
			}
			//cout<<i<<' '<<s[i]<<' '<<val<<endl;
			//for (int j=1;j<=5;j++) cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
		}
		long long res=-inf;
		for (int i=1;i<=5;i++) res=max({res,dp[n][i][0],dp[n][i][1]});
		cout<<res<<'\n';
	}
}