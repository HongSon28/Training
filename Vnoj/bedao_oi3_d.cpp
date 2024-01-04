#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
vector<vector<pair<int,long long>>>adj(N+5);
long long d[2][N+5],inf=1e18,res[N+5];
int p[N+5],t[N+5];
struct dat{
	int u,t;
	long long du;
	bool operator < (const dat &other) const{
		return du>other.du;
	}
};
priority_queue<dat>pq;
void dij() {
	for (int i=1;i<=n;i++) d[0][i]=d[1][i]=inf;
	for (int i=1;i<=k;i++) {
		pq.push({p[i],0,0});
		d[0][p[i]]=0;
	}
	while (!pq.empty()) {
		int u=pq.top().u,t=pq.top().t;
		long long du=pq.top().du;
		pq.pop();
		if (du!=d[t][u]) continue;
		for (auto [v,w]:adj[u]) {
			if (du+w<d[0][v]) {
				d[1][v]=d[0][v];
				d[0][v]=du+w;
				pq.push({v,0,du+w});
				pq.push({v,1,d[1][v]});
			} else if (du+w<d[1][v]) {
				d[1][v]=du+w;
				pq.push({v,1,du+w});
			}
		}
	}
}
int main() {
	freopen("milktea.inp","r",stdin);
	freopen("milktea.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++) cin>>p[i]>>t[i];
	dij();
	for (int i=1;i<=n;i++) res[i]=d[0][i];
	for (int i=1;i<=k;i++) {
		if (t[i]==1) res[p[i]]=d[1][i];
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}