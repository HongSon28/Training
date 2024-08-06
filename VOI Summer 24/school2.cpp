#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
struct ed{
	int v,a,b;
};
vector<ed>adj[N+5],rev[N+5];
struct dat{
	int u,d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int d[4][N+5],inf=1e9;
int res=inf;
void dij(int s,int type,int c,bool r) {
	for (int i=1;i<=n;i++) d[c][i]=inf;
	d[c][s]=0;
	pq.push({s,0});
	while (!pq.empty()) {
		int u=pq.top().u,du=pq.top().d;
		pq.pop();
		if (du!=d[c][u]) continue;
		if (r) {
			for (auto [v,a,b]:rev[u]) {
				int w;
				if (!type) w=a;
				else w=b;
				if (d[c][v]>du+w) {
					d[c][v]=du+w;
					pq.push({v,du+w});
				}
			}
		} else {
			for (auto [v,a,b]:adj[u]) {
				int w;
				if (!type) w=a;
				else w=b;
				if (d[c][v]>du+w) {
					d[c][v]=du+w;
					pq.push({v,du+w});
				}
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
    	int u,v,a,b;
    	cin>>u>>v>>a>>b;
    	adj[u].push_back({v,a,b});
    	rev[v].push_back({u,a,b});
    }
    dij(1,1,1,0);
    dij(k,0,2,1);
    dij(n,1,3,1);
    for (int i=1;i<=n;i++) {
    	//cout<<d[1][i]<<' '<<d[2][i]<<' '<<d[3][i]<<endl;
    	int x=d[1][i]+d[2][i],y=d[1][i]+d[3][i];
    	if (x<=59) res=min(res,y);
    }
    cout<<res;
}