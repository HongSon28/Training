#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,k;
long long a[N+5],inf=1e18;
vector<int>adj[N+5];
long long sz[N+5];
long long dp[N+5][N+5][3],t[N+5][3];
void maxi(long long &x,long long y) {
	if (x<y) x=y;
}
void dfs(int u,int par) {
	sz[u]=1;
	dp[u][0][0]=0;
	dp[u][1][1]=a[u];
	dp[u][1][2]=a[u];
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		for (int sz1=0;sz1<=sz[u];sz1++) {
			for (int sz2=0;sz2<=sz[v];sz2++) {
				for (int k=0;k<3;k++) {
					maxi(t[sz1+sz2][0],dp[u][sz1][0]+dp[v][sz2][k]);
					maxi(t[sz1+sz2][1],dp[u][sz1][1]+dp[v][sz2][k]);
					maxi(t[sz1+sz2][2],dp[u][sz1][2]+dp[v][sz2][k]);
				}
				maxi(t[sz1+sz2][1],dp[u][sz1][0]+dp[v][sz2][1]+a[u]);
				if (sz1+sz2) maxi(t[sz1+sz2-1][2],dp[u][sz1][1]+dp[v][sz2][1]);
			}
		}
		sz[u]+=sz[v];
		for (int i=0;i<=sz[u];i++) {
			for (int k=0;k<3;k++) {
				dp[u][i][k]=t[i][k];
				t[i][k]=-inf;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=n;j++) dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-inf;
	}
	for (int i=0;i<=n;i++)
		for (int k=0;k<3;k++) t[i][k]=-inf;
	dfs(1,0);
	cout<<max({dp[1][k][0],dp[1][k][1],dp[1][k][2]});
}