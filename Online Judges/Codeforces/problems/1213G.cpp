#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
struct edge{
	int u,v,w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
} ed[N+5];
struct query{
	int val,id;
	bool operator < (const query &other) const {
		return val<other.val;
	}
} q[N+5];
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
long long res[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));	
	cin>>n>>m;
	for (int i=1;i<n;i++) cin>>ed[i].u>>ed[i].v>>ed[i].w;
	sort(ed+1,ed+n);
	for (int i=1;i<=m;i++) {
		cin>>q[i].val;
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	int cur=1;
	for (int i=1;i<=m;i++) {
		res[q[i].id]=res[q[i-1].id];
		while (cur<n&&ed[cur].w<=q[i].val) {
			res[q[i].id]+=(long long)par[find_root(ed[cur].u)]*par[find_root(ed[cur].v)];
			Union(ed[cur].u,ed[cur].v);
			cur++;
		}
	}
	for (int i=1;i<=m;i++) cout<<res[i]<<' ';
}