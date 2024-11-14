#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,s,k;
long long a[N+5];
vector<pair<int,long long>>adj[N+5];
struct ed{
	int u,v;
	long long w;
};
vector<ed>edge;
long long res=1;
long long cur;
bool added[N+5];
struct dat{
	int u;
	long long d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int par[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	if ((u=find_root(u))==(v=find_root(v))) return;
	if (par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
    cin>>n>>m>>s>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    	edge.push_back({u,v,w});
    }
    cur=a[s];
    added[s]=true;
    for (auto [v,w]:adj[s]) pq.push({v,w});
    while (!pq.empty()) {
    	int u=pq.top().u;
    	long long d=pq.top().d;
    	pq.pop();
    	if (added[u]) continue;
    	if (d<=cur) {
    		added[u]=true;
    		res++;
    		cur+=a[u];
    		for (auto [v,w]:adj[u]) {
    			if (!added[v]) pq.push({v,w});
    		} 
    	}
    }
    if (k==0) {
    	cout<<res;
    	return 0;
    }
    for (auto [u,v,w]:edge) {
    	if (!added[u]&&!added[v]&&w<=cur) Union(u,v);
    }
    long long res2=res;
    for (auto [u,v,w]:edge) {
    	if (added[u]&&!added[v]) {
    		res2=max(res2,res-par[find_root(v)]);
    	} else if (added[v]&&!added[u]) {
    		res2=max(res2,res-par[find_root(u)]);
    	}
    }
    cout<<res2;
}