#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,k;
vector<vector<pair<int,long long>>>adj(N+5);
long long d[N+5][N+5],inf=1e18;
long long ed[N+5][N+5];
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij(int r) {
	for (int i=1;i<=n;i++) d[r][i]=inf;
	d[r][r]=0;
	pq.push({r,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[r][u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d[r][v]>d[r][u]+w) {
				d[r][v]=d[r][u]+w;
				ed[r][v]=w;
				pq.push({v,d[r][v]});
			} else if (d[r][v]==d[r][u]+w) {
				ed[r][v]=min(ed[r][v],w);
			}
		}
	}
}
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
    for (int i=1;i<=n;i++) dij(i);
    while (k--) {
    	int x,y,z;
    	cin>>x>>y>>z;
    	long long res=0;
    	for (int i=1;i<=n;i++) {
    		if (i==x||i==y||i==z) continue;
    		long long cur=d[x][i],mx=ed[x][i];
    		if (cur>d[y][i]) {
    			cur=d[y][i];
    			mx=ed[y][i];
    		} else if (cur==d[y][i]) mx=min(mx,ed[y][i]);
    		if (cur>d[z][i]) {
    			cur=d[z][i];
    			mx=ed[z][i];
    		} else if (cur==d[z][i]) mx=min(mx,ed[z][i]);
    		res+=mx;
    	}
    	cout<<res*100<<'\n';
    }
}