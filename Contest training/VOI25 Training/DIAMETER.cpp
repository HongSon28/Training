#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
vector<pair<int,long long>>adj[N+5];
long long f[N+5],g[N+5],dp[N+5],dp2[N+5],p[N+5],c[N+5],res;
void dfs1(int u,int par) {
	p[u]=par;
	long long mx1=0,mx2=0;
	for (auto pr:adj[u]) {
		int v=pr.first;
		long long w=pr.second;
		if (v==par) continue;
		c[v]=w;
		dfs1(v,u);
		f[u]=max(f[u],f[v]+w);
		dp[u]=max(dp[u],dp[v]);
		if (mx2<f[v]+w) mx2=f[v]+w;
		if (mx1<mx2) swap(mx1,mx2);
	}
	dp[u]=max(dp[u],mx1+mx2);
}
void dfs2(int u) {
	if (u!=1) {
		int par=p[u];
		g[u]=g[par]+c[u];
		dp2[u]=dp2[par];
		long long mx1=0,mx2=0;
		mx1=g[par];
		for (auto pr:adj[par]) {
			int v=pr.first;
			long long w=pr.second;
			if (v==p[par]||v==u) continue;
			g[u]=max(g[u],f[v]+c[u]+w);
			mx2=max(mx2,f[v]+w);
			if (mx1<mx2) swap(mx1,mx2);
			dp2[u]=max(dp2[u],dp[v]);
		}
		dp2[u]=max(dp2[u],mx1+mx2); 
	}
	for (auto pr:adj[u]) {
		int v=pr.first;
		if (v!=p[u]) dfs2(v);
	}
}
int main() {
	freopen("DIAMETER.INP","r",stdin);
	freopen("DIAMETER.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v,c;
    	cin>>u>>v>>c;
    	adj[u].push_back({v,c});
    	adj[v].push_back({u,c});
    }
    dfs1(1,0);
    res=dp[1];
    dfs2(1);
    for (int i=2;i<=n;i++) res=min(res,max(dp[i],dp2[i]));
    cout<<res;
}