#include<bits/stdc++.h>
using namespace std;
const int N=5e5,LG=__lg((int)1e5);
int n,m,k,q;
vector<vector<pair<long long,long long>>>adj(N+5),adj2(N+5);
long long d[N+5],inf=1e18;
vector<int>p;
pair<long long,long long>edge[N+5];
int par[N+5];
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
struct dat{
	long long u,d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
void dij() {
	for (int i=1;i<=n;i++) d[i]=inf;
	for (auto i:p) {
		pq.push({i,0});
		d[i]=0;
	}
	while (!pq.empty()) {
		long long u=pq.top().u,du=pq.top().d;
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
long long up[N+5][LG+5],rmq[N+5][LG+5],h[N+5];
void dfs(int u) {
	for (auto [v,w]:adj2[u]) {
		if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        rmq[v][0]=w;
        for (int j=1;j<=LG;j++) {
            up[v][j]=up[up[v][j-1]][j-1];
            rmq[v][j]=min(rmq[v][j-1],rmq[up[v][j-1]][j-1]);
        }
        dfs(v);
	}
} 
long long lca(int u,int v) {
	long long mn1=inf,mn2=inf;
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        int k=h[u]-h[v];
        for (int j=0;(1<<j)<=k;j++) {
            if ((k>>j)&1) {
                mn1=min(mn1,rmq[u][j]);
                u=up[u][j];
            }
        }
    }
    if (u==v) return min(mn1,mn2);
    int k=__lg(h[u]);
    for (int j=k;j>=0;j--) {
        if (up[u][j]!=up[v][j]){
        	mn1=min(mn1,rmq[u][j]);
        	mn2=min(mn2,rmq[v][j]);
            u=up[u][j];
            v=up[v][j];
        }
    }
    mn1=min(mn1,rmq[u][0]);
    mn2=min(mn2,rmq[v][0]);
    return min(mn1,mn2);
}
bool comp(pair<long long,long long>x,pair<long long,long long>y) {
	long long t1=min(d[x.first],d[x.second]);
	long long t2=min(d[y.first],d[y.second]);
	return t1>t2;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	long long u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    	edge[i]={u,v};
    }
    cin>>k;
    while (k--) {
    	int t;
    	cin>>t;
    	p.push_back(t);
    } 
    dij();
    sort(edge+1,edge+1+m,comp);
    for (int i=1;i<=m;i++) {
    	if (findroot(edge[i].first)==findroot(edge[i].second)) continue;
    	adj2[edge[i].first].push_back({edge[i].second,min(d[edge[i].first],d[edge[i].second])});
    	adj2[edge[i].second].push_back({edge[i].first,min(d[edge[i].first],d[edge[i].second])});
    	Union(edge[i].first,edge[i].second);
    	//cout<<edge[i].first<<' '<<edge[i].second<<' '<<min(d[edge[i].first],d[edge[i].second])<<endl;
    }
	dfs(1);
	cin>>q;
	while (q--) {
		int u,v;
		cin>>u>>v;
		cout<<lca(u,v)<<'\n';
	}
}