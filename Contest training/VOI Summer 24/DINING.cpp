#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,m,k;
vector<pair<int,long long>>adj[N+5];
int p[N+5];
long long y[N+5];
long long dn[N+5],dk[N+5],inf=1e18;
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
void dij1() {
	priority_queue<dat>pq;
	pq.push({n,0});
	for (int i=1;i<n;i++) dn[i]=inf;
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=dn[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (dn[v]>dn[u]+w) {
				dn[v]=dn[u]+w;
				pq.push({v,dn[v]});
			}
		}
	}
}
void dij2() {
	priority_queue<dat>pq;
	for (int i=1;i<=n;i++) dk[i]=inf;
	for (int i=1;i<=k;i++) {
		dk[p[i]]=dn[p[i]]-y[i];
		pq.push({p[i],dk[p[i]]});
	}
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=dk[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (dk[v]>dk[u]+w) {
				dk[v]=dk[u]+w;
				pq.push({v,dk[v]});
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
    for (int i=1;i<=k;i++) cin>>p[i]>>y[i];
    dij1();
    dij2();
    for (int i=1;i<n;i++) cout<<(dk[i]<=dn[i])<<'\n';
}