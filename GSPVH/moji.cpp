#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,k;
long long t;
int par[N+5];
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	if (par[u]>par[v]) swap(u,v); 
	par[u]+=par[v];
	par[v]=u;
}
struct edge{
	int u,v,index;
	long long w;
	bool operator < (const edge &other) const {
		if (w!=other.w) return w<other.w;
		return index<other.index;
	}
} e1[N+5],e2[N+5];
int shop[N+5];
int m1,m2;
long long res;
vector<int>id1,id2;
int main() {
	freopen("moji.inp","r",stdin);
	freopen("moji.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t>>n>>k;
    for (int i=1;i<=n;i++) par[i]=-1;
    for (int i=1;i<=k;i++) cin>>shop[i];
    for (int i=2;i<=k;i++) {
    	int u=find_root(shop[i]),v=find_root(shop[1]);
    	if (u!=v) Union(u,v);
    }
    cin>>m1;
    for (int i=1;i<=m1;i++) {
    	cin>>e1[i].u>>e1[i].v>>e1[i].w;
    	e1[i].index=i;
	}
	cin>>m2;
    for (int i=1;i<=m2;i++) {
    	cin>>e2[i].u>>e2[i].v>>e2[i].w;
    	e2[i].index=i;
	}
	sort(e1+1,e1+1+m1);
	sort(e2+1,e2+1+m2);
	for (int i=m1;i>=1;i--) {
		int u=find_root(e1[i].u),v=find_root(e1[i].v);
		if (u!=v) Union(u,v);
		else {
			res+=e1[i].w;
			id1.push_back(e1[i].index);
		}
	}
	for (int i=1;i<=m2;i++) {
		int u=find_root(e2[i].u),v=find_root(e2[i].v);
		if (u!=v) {
			Union(u,v);
			res+=e2[i].w;
			id2.push_back(e2[i].index);
		}
	}
	sort(id1.begin(),id1.end());
	sort(id2.begin(),id2.end());
	cout<<res*t<<'\n';
	cout<<id1.size()<<'\n';
	for (auto i:id1) cout<<i<<' ';
	cout<<'\n'<<id2.size()<<'\n';
	for (auto i:id2) cout<<i<<' ';
	
}