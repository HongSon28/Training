#include<bits/stdc++.h>
using namespace std;
const int N=18;
int n,m,k;
long long a[N],c[N][N];
vector<int>mask[N+1];
long long dp[2][N][(1<<N)];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) {
    	int x,y,v;
    	cin>>x>>y>>v;
    	x--;
    	y--;
    	c[x][y]=v;
    }
    for (int i=0;i<(1<<n);i++) {
    	if (__builtin_popcount(i)>m) continue;
    	mask[__builtin_popcount(i)].push_back(i);
    }
    for (int i=1;i<=m;i++) {
    	for (auto msk:mask[i]) {
    		for (int j=0;j<n;j++) {
    			dp[1][j][msk]=0;
    			if (!(msk>>j&1)) continue;
    			if (i==1) {
    				dp[1][j][msk]=a[j];
    				continue;
    			}
    			int lastmask=(msk&(~(1<<j)));
    			for (int p=0;p<n;p++) 
    				if (lastmask>>p&1) dp[1][j][msk]=max(dp[1][j][msk],dp[0][p][lastmask]+a[j]+c[p][j]);
    		}
    	}
    	for (auto msk:mask[i])
    		for (int j=0;j<n;j++)
    			if (msk>>j&1) dp[0][j][msk]=dp[1][j][msk];
    }
    //cout<<i<<' '<<j<<' '<<msk<<' '<<dp[1][j][msk]<<endl,
    long long res=0;
    for (auto msk:mask[m])
    	for (int i=0;i<n;i++)
    		if (msk>>i&1)
    			res=max(res,dp[0][i][msk]);
    cout<<res;
}