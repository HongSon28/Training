#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,w;
bool vis[N+5];
double m,inf=1e30;
double p[N+5][N+5],d[N+5];
pair<int,int> c[N+5];
struct dat{
	int u;
	double d;
	bool operator < (const dat &other) const{
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij() {
	for (int i=1;i<=n;i++) d[i]=inf;
	pq.push({1,0});
	d[1]=0;
	while (!pq.empty()) {
		int u=pq.top().u;
		double du=pq.top().d;
		pq.pop();
		if (du>d[u]) continue;
		for (int v=1;v<=n;v++) {
			if (v==u) continue;
			if (p[u][v]>m) continue;
			if (p[u][v]==0) {
				if (vis[v]) continue;
				if (d[v]>d[u]) {
					d[v]=d[u];
					vis[v]=true;
					pq.push({v,d[v]});
				}
			} else {
				if (d[v]>d[u]+p[u][v]) {
					d[v]=d[u]+p[u][v];
					pq.push({v,d[v]});
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(p,-1,sizeof(p));
    cin>>n>>w;
    cin>>m;	
    for (int i=1;i<=n;i++) cin>>c[i].first>>c[i].second;
    for (int i=1;i<=w;i++) {
    	int u,v;
    	cin>>u>>v;
    	p[u][v]=p[v][u]=0;
    }
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<i;j++) {
    		if (p[i][j]==0||i==j) continue;
    		double t=sqrt((double)(c[i].first-c[j].first)*(c[i].first-c[j].first)+(double)(c[i].second-c[j].second)*(c[i].second-c[j].second));
    		p[i][j]=p[j][i]=t;
    	}
    }
    dij();
    if (d[n]==inf) cout<<-1;
    else cout<<(int)(d[n]*1000);
}