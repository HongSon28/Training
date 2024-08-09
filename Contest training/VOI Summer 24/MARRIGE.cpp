#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=18;
int n,m,q;
vector<int>adj[N+5],tree[N+5];
int low[N+5],num[N+5],tim;
int up[N+5][LG+5],h[N+5];
void dfs(int u,int par) {
	num[u]=low[u]=++tim;
	//cout<<u<<' '<<tim<<endl;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (!num[v]) {
			dfs(v,u);
			tree[u].push_back(v);
			tree[v].push_back(u);
			//cout<<u<<' '<<v<<endl;
			low[u]=min(low[u],low[v]);
		} else low[u]=min(low[u],num[v]);
	}
} 
void dfs2(int u,int par) {
	h[u]=h[par]+1;
	for (auto v:tree[u]) {
		if (v==par) continue;
		up[v][0]=u;
		for (int i=1;i<=LG;i++) up[v][i]=up[up[v][i-1]][i-1];
		dfs2(v,u);
	}
}
int lca(int u,int v) {
	if (h[u]<h[v]) swap(u,v);
	int k=h[u]-h[v];
	for (int i=0;i<=LG;i++) {
		if (k>>i&1) u=up[u][i];
	}
	if (u==v) return u;
	k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
vector<int>v;
int p[N+5];
int check() {
	for (int i=0;i<(int)v.size();i++) {
		if (p[i]==-1) return 0;
	}
	for (int i=1;i<(int)v.size();i++) {
		if (p[i]!=p[i-1]) return 1;
	}
	return 2;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    //for (int i=1;i<=n;i++) cout<<low[i]<<' '<<num[i]<<endl; 
    cin>>q;
    while (q--) {
    	int u,k;
    	cin>>u>>k;
    	v.clear();
    	while (k--) {
    		int t;
    		cin>>t;
    		v.push_back(t);;
    	}
    	for (int i=0;i<(int)v.size();i++) {
    		if (lca(v[i],u)!=u) p[i]=-1;
    		else {
    			int temp=h[v[i]]-h[u]-1;
    			p[i]=v[i];
    			for (int j=0;j<=LG;j++) {
    				if (temp>>j&1) p[i]=up[p[i]][j];
    			}
    		}
    	}
    	if (check()==2) cout<<"YES"<<'\n';
    	else if (check()==1) cout<<"NO"<<'\n';
    	else {
    		bool flag=true;
    		for (int i=0;i<(int)v.size();i++) {
    			if (p[i]==-1) continue;
    			if (low[p[i]]>=num[u]) {
    				flag=false;
    				break;
    			}
    		}
    		if (flag) cout<<"YES"<<'\n';
    		else cout<<"NO"<<'\n';
    	}
    }
}