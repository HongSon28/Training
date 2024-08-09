#include<bits/stdc++.h>
using namespace std;
const int N=1e4,M=3e4,K=100;
int n,m,k;
vector<vector<pair<int,long long>>>adj(N+5);
vector<vector<int>>adj2(K+5);
struct house{
	int h;
	long long t,p;
	bool operator < (const house &other) {
		if (t!=other.t) return t<other.t;
		return p<other.p;
	}
}a[K+5];
long long dist[N+5],inf=1e18;
struct dat{
	int u;
	long long du;
	bool operator < (const dat &other) const {
		return du>other.du;
	}
};
priority_queue<dat>pq;
void dij(int s) {
	pq.push({s,0});
	for (int i=1;i<=n;i++) dist[i]=inf;
	dist[s]=0;
	while (!pq.empty()) {
		int u=pq.top().u;
		long long du=pq.top().du;
		pq.pop();
		if (du!=dist[u]) continue;
		for (auto [v,w]:adj[u]) {
			if (dist[v]>dist[u]+w) {
				dist[v]=dist[u]+w;
				pq.push({v,dist[v]});
			}
		}
	}
}
int mx[N+5],my[N+5],vis[N+5],res,tt;
bool dfs(int u) {
	if (vis[u]!=tt) vis[u]=tt;
	else return false;
	for (auto v:adj2[u]) {
		if (!mx[v]||dfs(mx[v])) {
			mx[v]=u;
			my[u]=v;
			return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++) cin>>a[i].h;
	for (int i=1;i<=k;i++) cin>>a[i].t;
	for (int i=1;i<=k;i++) cin>>a[i].p;
	sort(a+1,a+1+k);
	for (int i=1;i<=m;i++) {
		int u,v;
		long long w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	for (int i=1;i<=k;i++) {
		dij(a[i].h);
		for (int j=1;j<=k;j++) {
			if (i==j) continue;
			if (a[i].t+a[i].p+dist[a[j].h]<=a[j].t) {
				adj2[i].push_back(j);
			}
		}
	}
	for (int i=1;i<=k;i++) {
		if (!my[i]) {
			tt++;
			dfs(i);
		}
	}
	for (int i=1;i<=k;i++) res+=(my[i]>0);
	cout<<k-res;
}