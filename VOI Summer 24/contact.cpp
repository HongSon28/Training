#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int par[18][N+5];
int mod=1e9+7;
int find_root(int id,int u) {
	if (par[id][u]<0) return u;
	return par[id][u]=find_root(id,par[id][u]);
}
void Union(int id,int u,int v) {
	u=find_root(id,u),v=find_root(id,v);
	if (u==v) return;
	if (par[id][u]>par[id][v]) swap(u,v);
	par[id][u]+=par[id][v];
	par[id][v]=u;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	memset(par,-1,sizeof(par));
	cin>>n>>m;
	int cnt=0;
	while (m--) {
		int p,q,l;
		cin>>p>>q>>l;
		for (int i=17;i>=0;i--) {
			if (l>=(1<<i)) {
				Union(i,p,q);
				l-=(1<<i);
				p+=(1<<i);
				q+=(1<<i);
			}
		}
	}
	for (int i=17;i>=1;i--) {
		for (int u=1;u<=n;u++) {
			int v=find_root(i,u);
			if (u==v) continue;
			Union(i-1,u,v);
			Union(i-1,u+(1<<(i-1)),v+(1<<(i-1)));
		}
	}
	for (int i=1;i<=n;i++) {
		if (find_root(0,i)==i) cnt++;
	}
	int res=1;
	while (cnt--) {
		res*=2;
		if (res>=mod) res-=mod;
	}
	cout<<res;
}