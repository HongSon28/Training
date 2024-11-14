#include<bits/stdc++.h>
using namespace std;
const int N=4e5,LG=__lg(N);
int n,m;
struct query{
	int type,u,v;
	long long w;
} q[N+5];
int par[N+5],up[N+5][LG+5],h[N+5];
long long rmq[N+5][LG+5];
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
vector<vector<pair<int,long long>>>adj(N+5);
void dfs(int u) {
	for (auto [v,w]:adj[u]) {
		if (v==up[u][0]) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		rmq[v][0]=w;
		for (int k=1;k<=LG;k++) {
			up[v][k]=up[up[v][k-1]][k-1];
			rmq[v][k]=rmq[v][k-1]+rmq[up[v][k-1]][k-1];
		}
		dfs(v);
	}
}
long long lca(int u,int v) {
	long long ans=0;
	if (h[u]!=h[v]) {
		if (h[u]<h[v]) swap(u,v);
		int k=h[u]-h[v];
		for (int i=0;(1<<i)<=k;i++) {
			if (k>>i&1) {
				ans+=rmq[u][i];
				u=up[u][i];
			}
		}
	}
	if (u==v) return ans;
	int k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			ans+=rmq[u][i]+rmq[v][i];
			u=up[u][i];
			v=up[v][i];
		}
	}
	return ans+rmq[u][0]+rmq[v][0];
}
struct dsu{
	int par,u,v,mx;
} p[N+5];
int root(int u) {
	if (p[u].par<0) return u;
	return p[u].par=root(p[u].par);
}
void join(int x,int y,long long w) {
	int u=root(x),v=root(y);
	if (p[v].par<p[u].par) {
		swap(u,v);
		swap(x,y);
	}
	p[u].par+=p[v].par;
	p[v].par=u;
	long long t1=lca(x,p[u].u),left=p[u].u;
	if (lca(x,p[u].v)>t1) {
		t1=lca(x,p[u].v);
		left=p[u].v;
	}
	long long t2=lca(y,p[v].u),right=p[v].u;
	if (lca(y,p[v].v)>t2) {
		t2=lca(y,p[v].v);
		right=p[v].v;
	}
	if (p[u].mx<p[v].mx) {
		p[u].mx=p[v].mx;
		p[u].u=p[v].u,p[u].v=p[v].v;
	}
	if (p[u].mx<t1+t2+w) {
		p[u].mx=t1+t2+w;
		p[u].u=left;
		p[u].v=right;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	cin>>q[i].type;
    	if (q[i].type==1) {
    		cin>>q[i].u>>q[i].v>>q[i].w;
    		int u=find_root(q[i].u),v=find_root(q[i].v);
    		if (u==v) continue;
    		Union(u,v);
    		adj[q[i].u].push_back({q[i].v,q[i].w});
    		adj[q[i].v].push_back({q[i].u,q[i].w});
    		//cout<<q[i].u<<' '<<q[i].v<<' '<<q[i].w<<endl;
    	} else cin>>q[i].u;
    }
    for (int i=1;i<=n;i++) {
    	if (h[i]==0) dfs(i);
    	p[i].par=-1;
    	p[i].u=p[i].v=i;
    	p[i].mx=0;
    }
    for (int i=1;i<=m;i++) {
    	if (q[i].type==1) {
    		if (root(q[i].u)==root(q[i].v)) continue;
    		//cout<<q[i].u<<' '<<q[i].v<<' '<<q[i].w<<endl;
    		join(q[i].u,q[i].v,q[i].w);
    	} else {
    		int r=root(q[i].u);
    		int x=p[r].u,y=p[r].v;
    		//cout<<q[i].u<<' '<<x<<' '<<y<<' '<<lca(q[i].u,x)<<' '<<lca(q[i].u,y)<<endl;
    		cout<<max(lca(q[i].u,x),lca(q[i].u,y))<<'\n';
    	}
    }
}