#include<bits/stdc++.h>
using namespace std;
const int N=500;
int mod=1e9+7;
int n;
char a[N+5][N+5];
int dp[N+5][N+5][2];
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n) {
    	if(n==0) break;
    	for (int i=1;i<=n;i++) 
    		for (int j=1;j<=n;j++)
    			cin>>a[i][j];
    	memset(dp,0,sizeof(dp));
    	dp[1][n][0]=1;
    	for (int k=1;k<=n-1;k++) {
    		for (int i=1;i<=n,i<=k+1;i++) {
    			int j=k-i+2;
    			for (int u=n;u>=i,n-u<=k;u--) {
    				int v=n-(k-(n-u));
    				if (a[i][j]!=a[u][v]) continue;
    				add(dp[i][u][1],dp[i-1][u+1][0]);
    				add(dp[i][u][1],dp[i][u][0]);
    				add(dp[i][u][1],dp[i-1][u][0]);
    				add(dp[i][u][1],dp[i][u+1][0]);
    				//cout<<i<<' '<<j<<' '<<u<<' '<<v<<' '<<k<<' '<<dp[i][u][k]<<endl;
    			}
    		}
    		for (int i=1;i<=n,i<=k+1;i++) {
    			for (int u=n;u>=i,n-u<=k;u--) {
    				dp[i][u][0]=dp[i][u][1];
    				dp[i][u][1]=0;
    			}
    		} 
    	}
    	int res=0;
    	for (int i=1;i<=n;i++) add(res,dp[i][i][0]);
    	cout<<res<<'\n';
    }
}