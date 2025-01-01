#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<pair<int,long long>>adj[N+5],rev[N+5];
long long d1[N+5],d2[N+5],inf=1e18;
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij1() {
	for (int i=2;i<=n;i++) d1[i]=inf;
	pq.push({1,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long d=pq.top().d;
		pq.pop();
		if (d!=d1[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d1[v]>d1[u]+w) {
				d1[v]=d1[u]+w;
				pq.push({v,d1[v]});
			}
		}
	}
}
void dij2() {
	for (int i=1;i<=n;i++) {
		d2[i]=d1[i];
		if (d2[i]!=inf) pq.push({i,d2[i]});
	}
	while (!pq.empty()) {
		int u=pq.top().u;
		long long d=pq.top().d;
		pq.pop();
		if (d!=d2[u]) continue;
		for (auto [v,w]:rev[u]) {
			if (d2[v]>d2[u]+w) {
				d2[v]=d2[u]+w;
				pq.push({v,d2[v]});
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
    	rev[v].push_back({u,w});
    }
    dij1();
    dij2();
    for (int i=2;i<=n;i++) 
    	if (d2[i]==inf) cout<<-1<<' ';
    	else cout<<d2[i]<<' ';
}