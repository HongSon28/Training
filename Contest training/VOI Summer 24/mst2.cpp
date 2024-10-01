#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int sub,n,m;
struct edge{
	int u,v,id;
	long long w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
} a[N+5];
int par[N+5];
bool res[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	u=find_root(u),v=find_root(v);
	if (u==v) return;
	if (par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
int main() {
	freopen("mst.inp","r",stdin);
	freopen("mst.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
    cin>>sub>>n>>m;
	for (int i=1;i<=m;i++) {
		cin>>a[i].u>>a[i].v>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+1+m);
	vector<edge>cur;
	for (int i=1;i<=m;i++) {
		cur.push_back(a[i]);
		if (a[i].w==a[i+1].w) continue;
		for (auto [u,v,id,w]:cur) {
			if (find_root(u)!=find_root(v)) res[id]=true;
		}
		for (auto [u,v,id,w]:cur) Union(u,v);
		cur.clear();
	}
	for (int i=1;i<=m;i++) {
		if (res[i]) cout<<"Yes"<<' ';
		else cout<<"No"<<' ';
	}
}