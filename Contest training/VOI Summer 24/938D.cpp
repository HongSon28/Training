#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
vector<pair<int,long long>>adj[N+5];
long long a[N+5];
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
long long d[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		w*=2;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		d[i]=a[i];
		pq.push({i,a[i]});
	}
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pq.push({v,d[v]});
			}
		}
	}
	for (int i=1;i<=n;i++) cout<<d[i]<<' ';
}