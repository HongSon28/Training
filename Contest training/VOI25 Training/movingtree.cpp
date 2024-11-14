#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,c;
long long p[N+5],k,val;
vector<pair<int,long long>>adj[N+5];
long long dp[N+5][N+5],temp[N+5],inf=1e18;
long long sz[N+5],sum[N+5];
long long cost(int u,int i) {
	long long cnt=abs(sz[u]*val+i-sum[u]);
	return (cnt+c-1)/c;
}
void dfs(int u,int par) {
	sz[u]=1;
	sum[u]=p[u];
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		sum[u]+=sum[v]; 	
	}
	if (adj[u].size()==1&&par!=0) return;
	int cur=1;
	for (int i=2;i<=sz[u];i++) dp[u][i]=inf;
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		for (int i=0;i<=min(cur,(int)k);i++) {
			temp[i]=dp[u][i];
			dp[u][i]=inf;
		}
		for (int i=0;i<=cur;i++) {
			for (int j=0;j<=sz[v];j++) {
				int t=i+j;
				if (t>k) break;
				dp[u][t]=min(dp[u][t],temp[i]+dp[v][j]+cost(v,j)*w);
			}
		}
		cur+=sz[v];
	}
	//for (int i=0;i<=k;i++) cout<<u<<' '<<i<<' '<<dp[u][i]<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>c;
    for (int i=1;i<=n;i++) {
    	cin>>p[i];
    	p[0]+=p[i];
    }
    k=p[0]%n,val=p[0]/n;
    for (int i=1;i<n;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dfs(1,0);
    cout<<dp[1][k];
}