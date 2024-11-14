#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<int>adj[N+5];
int low[N+5],num[N+5],tim;
int par[N+5];
long long res;
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
	if (par[u]>par[v]) swap(u,v);
	par[u]+=par[v];
	par[v]=u;
}
long long calc(int sz) {
	return sz*(sz-1)/2-(sz-1);
}
void dfs(int u,int p) {
	low[u]=num[u]=++tim;
	for (auto v:adj[u]) {
		if (v==p) continue;
		if (!num[v]) {
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if (low[v]==num[v]) {
				int x=find_root(u),y=find_root(v);
				long long szx=-par[x],szy=-par[y];
				res-=calc(szx);
				res-=calc(szy);
				Union(x,y);
				szx=-par[find_root(u)];
				res+=calc(szx);
				//cout<<u<<' '<<v<<endl;
			}
		} else low[u]=min(low[u],num[v]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(par,-1,sizeof(par));
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	cout<<res;
}