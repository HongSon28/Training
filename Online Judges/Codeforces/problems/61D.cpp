#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
vector<pair<int,long long>>adj[N+5];
long long f[N+5],g[N+5];
void dfs(int u,int par) {
	long long mn=0;
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		g[u]+=g[v]+2*w;
		f[u]+=g[v]+2*w;
		mn=min(mn,-g[v]-2*w+f[v]+w);
	}
	f[u]+=mn;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dfs(1,0);
    cout<<f[1];
}