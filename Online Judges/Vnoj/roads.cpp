#include<bits/stdc++.h>
using namespace std;
const int N=100,K=1e4;
int n,k,r,inf=1e9;
struct ed{
	int v,l,t;
};
vector<vector<ed>>adj;
int d[N+5][K+5];
struct dat{
	int u,w,d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int solve() {
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++)
			d[i][j]=inf;
	d[1][0]=0;
	while (!pq.empty()) pq.pop();
	pq.push({1,0,0});
	while (!pq.empty()) {
		int u=pq.top().u,w=pq.top().w,du=pq.top().d;
		pq.pop();
		if (du!=d[u][w]) continue;
		if (u==n) return du;
		for (auto [v,l,t]:adj[u]) {
			if (w+t<=k&&du+l<d[v][w+t]) {
				d[v][w+t]=du+l;
				pq.push({v,w+t,d[v][w+t]});
			}
		}
	}
	return -1;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	int t;
	cin>>t;
	while (t--) {
		adj.clear();
		cin>>k>>n>>r;
		adj.resize(n+1);
		for (int i=1;i<=r;i++) {
			int u,v,l,t;
			cin>>u>>v>>l>>t;
			adj[u].push_back({v,l,t});
		}
		cout<<solve()<<'\n';
	}
}