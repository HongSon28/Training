#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<pair<int,long long>>adj[N+5];
struct dat {
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
long long d[N+5],inf=1e18;
int trace[N+5];
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
    for (int i=2;i<=n;i++) d[i]=inf;
	pq.push({1,0});
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().d;
		pq.pop();
		if (du!=d[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (d[v]>d[u]+w) {
				d[v]=d[u]+w;
				pq.push({v,d[v]});
				trace[v]=u;
			}
		}
	}
	if (d[n]==inf) {
		cout<<-1;
		return 0;
	}
	vector<int>res;
	res.push_back(n);
	while (res.back()!=1) res.push_back(trace[res.back()]);
	reverse(res.begin(),res.end());
	for (auto i:res) cout<<i<<' ';
}