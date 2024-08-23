#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,t;
long long c[N+5];
vector<pair<int,int>>adj[N+5];
vector<int>adj2[N+5];
int d[N+5],inf=1e9;
struct dat{
	int u,d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int par[N+5];
long long res;
void dij() {
	for (int i=2;i<=n;i++) d[i]=inf;
	pq.push({1,0});
	while (!pq.empty()) {
		int u=pq.top().u,du=pq.top().d;
		pq.pop();
		if (du!=d[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pq.push({v,d[v]});
				par[v]=u;
			} else if (d[v]==d[u]+w) par[v]=min(par[v],u);
		}
	}
	for (int i=2;i<=n;i++) {
		adj2[par[i]].push_back(i); 
	}
}
void dfs(int u) {
	for (auto v:adj2[u]) {
		dfs(v);
		c[u]+=c[v];
	}
	res=max(res,c[u]*(d[u]-t));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>t;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dij();
    dfs(1);
    cout<<res;
}