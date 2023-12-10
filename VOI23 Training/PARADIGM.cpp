#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long w[N+5],res;
struct edge{
	int u,v,w;
	bool operator < (const edge &other) const {
		return w<other.w;
	}
} ed[N+5];
pair<long long,int>par[N+5];
int find_root(int u) {
	if (par[u].second<0) return u;
	return par[u].second=find_root(par[u].second);
}
void Union(int u,int v) {
	if ((u=find_root(u))==(v=find_root(v))) return;
	if (par[u].second>par[v].second) swap(u,v);
	par[u].second+=par[v].second;
	par[u].first=max(par[u].first,par[v].first);
	par[v].second=u;
}
int main() {
	freopen("PARADIGM.INP ","r",stdin);
	freopen("PARADIGM.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>w[i];
    	par[i]={w[i],-1};
    }	
    for (int i=1;i<n;i++) {
    	cin>>ed[i].u>>ed[i].v;
		ed[i].w=max(w[ed[i].u],w[ed[i].v]);
	}
	sort(ed+1,ed+n);
	for (int i=1;i<n;i++) {
		int x=find_root(ed[i].u),y=find_root(ed[i].v);
		res+=par[x].first+par[y].first;
		Union(ed[i].u,ed[i].v);
	}
	cout<<res;
}