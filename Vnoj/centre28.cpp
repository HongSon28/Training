#include<bits/stdc++.h>
using namespace std;
const int N=3e4;
int n,m;
vector<vector<pair<int,long long>>>adj(N+5);
vector<int>res;
long long d[2][N+5],f[2][N+5],inf=1e18;
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij(int t,int s) {
	for (int i=1;i<=n;i++) d[t][i]=inf;
	d[t][s]=0;
	f[t][s]=1;
	pq.push({s,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[t][u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d[t][u]+w<d[t][v]) {
				d[t][v]=d[t][u]+w;
				f[t][v]=f[t][u];
				pq.push({v,d[t][v]});
			} else if (d[t][u]+w==d[t][v]) {
				f[t][v]+=f[t][u];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dij(0,1);
    dij(1,n);
    for (int i=2;i<n;i++) {
    	if (d[0][i]+d[1][i]>d[0][n]) res.push_back(i);
    	else if (f[0][i]*f[1][i]<f[0][n]) res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for (auto i:res) cout<<i<<'\n';
}
