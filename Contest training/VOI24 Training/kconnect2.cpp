#include<bits/stdc++.h>
using namespace std;
const int N=3e5,LG=__lg(N);
int n,m,k;
pair<int,int>edge[N+5];
int h[N+5],up[N+5][LG+5];
vector<vector<pair<int,int>>>adj(N+5);
int par[N+5],res[N+5],d[N+5],id[N+5];
bool used[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]); 
}
void Union(int u,int v) {
	u=find_root(u);
	v=find_root(v);
	if (par[v]<par[u]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
void dfs_lca(int u) {
	for (auto [v,i]:adj[u]) {
		if (v==up[u][0]) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		id[v]=i;
		for (int k=1;k<=LG;k++) up[v][k]=up[up[v][k-1]][k-1];
		dfs_lca(v);
	}
}
int lca(int u,int v) {
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int i=0;(1<<i)<=k;i++) {
			if (k>>i&1) u=up[u][i];
		}
	}
	if (u==v) return u;
	int k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
void dfs(int u) {
	for (auto [v,i]:adj[u]) {
		if (v==up[u][0]) continue;
		dfs(v);
		d[u]+=d[v];
	}
	if (d[u]<0) used[id[u]]=true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
    	cin>>edge[i].first>>edge[i].second;
    	int u=find_root(edge[i].first),v=find_root(edge[i].second);
    	if (u==v) res[i]=0;
    	else {
    		res[i]=1;
    		Union(u,v);
    		adj[edge[i].first].push_back({edge[i].second,i});
    		adj[edge[i].second].push_back({edge[i].first,i});
    	}
    }
    dfs_lca(1);
    while (k--) {
    	int a,b;
    	cin>>a>>b;
    	int l=lca(a,b);
    	d[a]--;
    	d[b]--;
    	d[l]+=2;
    }
    dfs(1);
    for (int i=1;i<=m;i++) cout<<(res[i]&used[i])<<' ';
}