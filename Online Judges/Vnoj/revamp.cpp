#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,k;
vector<vector<pair<int,long long>>>adj(N+5);
long long d[N+5][25],inf=1e18,res=inf;
struct dat{
	int u,t;
	long long d;
	bool operator < (const dat& other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	pq.push({1,0});
	for (int i=1;i<=n;i++) {
		for (int j=0;j<=k;j++) {
			d[i][j]=inf;
		}
	}
	d[1][0]=0;
	while (!pq.empty()) {
		int u=pq.top().u,t=pq.top().t;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[u][t]) continue;
		if (u==n) res=min(res,du);
		for (auto [v,w]:adj[u]) {
			if (t<k&&d[v][t+1]>d[u][t]) {
				d[v][t+1]=d[u][t];
				pq.push({v,t+1,d[v][t+1]});
			}
			if (d[v][t]>d[u][t]+w) {
				d[v][t]=d[u][t]+w;
				pq.push({v,t,d[v][t]});
			}
		}
	}
	cout<<res;
}