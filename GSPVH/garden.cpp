#include<bits/stdc++.h>
using namespace std;
const int N=2207;
int n,m,k;
long long a[N+5][N+5];
long long dp[N+5][N+5][11];
long long inf=1e18;
pair<long long,long long>row[N+5],col[N+5];
void maxi(long long &x,const long long y) {
	if (x<y) x=y;
}
void update(pair<long long,long long> &x,const long long y) {
	if (y>x.first) {
		x.second=x.first;
		x.first=y;
	} else maxi(x.second,y);
}
int main() {
	freopen("garden.inp","r",stdin);
	freopen("garden.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i) {
    	for (int j=1;j<=m;++j) {
    		cin>>a[i][j];
    		for (int t=0;t<=k;++t) dp[i][j][t]=-inf;
    	}
    }
    for (int i=1;i<=n;++i) dp[i][1][0]=a[i][1];
    for (int t=0;t<=k;++t) {
    	for (int j=1;j<m;++j) {
    		maxi(dp[1][j+1][t],dp[1][j][t]+a[1][j+1]);
    		maxi(dp[2][j+1][t],dp[1][j][t]+a[2][j+1]);
    		for (int i=2;i<n;++i) {
    			maxi(dp[i-1][j+1][t],dp[i][j][t]+a[i-1][j+1]);
    			maxi(dp[i+1][j+1][t],dp[i][j][t]+a[i+1][j+1]);
    			maxi(dp[i][j+1][t],dp[i][j][t]+a[i][j+1]);
    		}
    		maxi(dp[n-1][j+1][t],dp[n][j][t]+a[n-1][j+1]);
    		maxi(dp[n][j+1][t],dp[n][j][t]+a[n][j+1]);
    	}
    	if (t==k) break;
    	for (int i=1;i<=n;++i) row[i]={-inf,-inf};
    	for (int j=1;j<=m;++j) col[j]={-inf,-inf};
    	for (int i=1;i<=n;++i) {
    		for (int j=1;j<=m;++j) {
    			update(row[i],dp[i][j][t]);
    			update(col[j],dp[i][j][t]);
    		}
    	}
    	for (int i=1;i<=n;++i) {
    		for (int j=1;j<=m;++j) {
    			long long mrow=row[i].second;
    			if (row[i].first!=dp[i][j][t]) mrow=row[i].first;
    			long long mcol=col[j].second;
    			if (col[j].first!=dp[i][j][t]) mcol=col[j].first;
    			maxi(mrow,mcol);
    			dp[i][j][t+1]=mrow+a[i][j];
    		}
    	}
    }
    long long res=-inf;
    for (int i=1;i<=n;++i) {
    	for (int t=0;t<=k;++t) maxi(res,dp[i][m][t]);
    }
    cout<<res;
}