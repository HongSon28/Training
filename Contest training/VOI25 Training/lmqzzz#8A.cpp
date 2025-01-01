#include<bits/stdc++.h>
using namespace std;
const int N=100,M=500;
int n;
int a[N+5],b[N+5],sum;
int dp[N+5][M+5][M+5],inf=1e9;
void mini(int &x,int y) {
	if (x>y) x=y;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i]>>b[i];
    	sum+=b[i];
    }
    if (sum%3!=0) {
    	cout<<-1;
    	return 0;
    }
    sum/=3;
    for (int i=0;i<=n;i++)
	    for (int j=0;j<=sum;j++)
	    	for (int k=0;k<=sum;k++)
    		dp[i][j][k]=inf;
	dp[0][0][0]=0;
	for (int i=1;i<=n;i++) {
		for (int x=0;x<=sum;x++) {
			for (int y=0;y<=sum;y++) {
				mini(dp[i][x][y],dp[i-1][x][y]+(a[i]!=3));
				if (x>=b[i]) mini(dp[i][x][y],dp[i-1][x-b[i]][y]+(a[i]!=1));
				if (y>=b[i]) mini(dp[i][x][y],dp[i-1][x][y-b[i]]+(a[i]!=2));
			}
		} 
	}
	if (dp[n][sum][sum]==inf) cout<<-1;
	else cout<<dp[n][sum][sum];
}