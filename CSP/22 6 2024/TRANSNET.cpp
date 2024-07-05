#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k,s,t;
vector<vector<pair<int,long long>>>adj(N+5);
vector<vector<pair<int,long long>>>rev_adj(N+5);
long long d1[N+5],d2[N+5],inf=1e18,res;
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int main() {
	freopen("TRANSNET.INP","r",stdin);
	freopen("TRANSNET.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>k>>s>>t;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	long long w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	rev_adj[v].push_back({u,w});
    }
    for (int i=1;i<=n;i++) d1[i]=d2[i]=inf;
    d1[s]=0;
    pq.push({s,d1[s]});
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
    res=d1[t];
    d2[t]=0;
    pq.push({t,d2[t]});
    while (!pq.empty()) {
    	int u=pq.top().u;
    	long long d=pq.top().d;
    	pq.pop();
    	if (d!=d2[u]) continue;
    	for (auto [v,w]:rev_adj[u]) {
    		if (d2[v]>d2[u]+w) {
    			d2[v]=d2[u]+w;
    			pq.push({v,d2[v]});
    		}
    	}
    }
    for (int i=1;i<=k;i++) {
    	int u,v;
    	long long w;
    	cin>>u>>v>>w;
    	res=min(res,d1[u]+d2[v]+w);
    	res=min(res,d1[v]+d2[u]+w);
    }
    if (res==inf) cout<<-1; 
	else cout<<res;
}