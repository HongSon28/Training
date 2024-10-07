#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,k;
long long dp[N+5][N+5][11],inf=1e18;
struct edge{
	int u,v,w;
};
vector<edge>adj[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<m;j++) {
    		int w;
    		cin>>w;
    		adj[i][j].push_back({i,j+1,w});
    		adj[i][j+1].push_back({i,j,w});
    	}
    }	
    for (int i=1;i<n;i++) {
    	for (int j=1;j<=m;j++) {
    		int w;
    		cin>>w;
    		adj[i][j].push_back({i+1,j,w});
    		adj[i+1][j].push_back({i,j,w});
    	}
    }
    if (k&1) {
    	for (int i=1;i<=n;i++) {
    		for (int j=1;j<=m;j++) cout<<-1<<' ';
    		cout<<'\n';
    	}
    	return 0;
    }
    k/=2;
    for (int t=1;t<=k;t++) {
	    for (int i=1;i<=n;i++) {
	    	for (int j=1;j<=m;j++) {
	    		dp[i][j][t]=inf;
	    		for (auto [x,y,w]:adj[i][j]) dp[i][j][t]=min(dp[i][j][t],dp[x][y][t-1]+w);
	    	}
	    }
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) cout<<dp[i][j][k]*2<<' ';
    	cout<<'\n';
    }
}