#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,b,mod;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int a[N+5];
int dp[2][N+1][N+1];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>b>>mod;
    for (int i=1;i<=n;i++) cin>>a[i];	
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=m;j++) {
			for (int k=0;k<=b;k++) {
				dp[1][j][k]=dp[0][j][k];
				if (j>0&&k>=a[i]) add(dp[1][j][k],dp[1][j-1][k-a[i]]);
			}
		}
		for (int j=0;j<=m;j++)
			for (int k=0;k<=b;k++) {
				//cout<<i<<' '<<j<<' '<<k<<' '<<dp[0][j][k]<<' '<<dp[1][j][k]<<endl;
				dp[0][j][k]=dp[1][j][k];
			}
	}
	int res=0;
	for (int k=0;k<=b;k++) add(res,dp[0][m][k]);
	cout<<res;
}