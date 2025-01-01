#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long c[N+5];
vector<pair<int,long long>>adj[N+5];
long long f[N+5],g[N+5];
void dfs(int u,int par) {
	long long mx1=0,mx2=0;
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		g[u]=max(g[u],g[v]-w);
		f[u]=max(f[u],f[v]);
		mx2=max(mx2,g[v]-w);
		if (mx2>mx1) swap(mx1,mx2);
	}
	g[u]+=c[u];
	f[u]=max(f[u],mx1+mx2+c[u]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<n;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dfs(1,0);
    cout<<f[1];
}