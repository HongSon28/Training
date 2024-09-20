#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
int s[N+5],w[N+5],deg[N+5];
vector<pair<int,long long>>adj[N+5];
struct ed{
	int u,v,w;
};
vector<ed>edge;
long long d[N+5],inf=1e18,res;
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
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
    	edge.push_back({u,v,w});
    	edge.push_back({v,u,w});
    }
    for (int i=1;i<=k;i++) {
    	cin>>s[i]>>w[i];
    	adj[1].push_back({s[i],w[i]});
    	adj[s[i]].push_back({1,w[i]});
    	edge.push_back({1,s[i],w[i]});
    	edge.push_back({s[i],1,w[i]});
    }
    dij();
    for (auto [u,v,w]:edge) {
    	if (d[u]+w==d[v]) {
    		deg[v]++;
    	}
    }
    for (int i=1;i<=k;i++) {
    	if (d[1]+w[i]==d[s[i]]) {
    		if (deg[s[i]]>1) {
    			deg[s[i]]--;
    			res++;
    		}
    	} else if (d[s[i]]+w[i]==d[1]) {
    		if (deg[1]>1) {
    			deg[1]--;
    			res++;
    		}
    	} else res++;
    }
    cout<<res;
}