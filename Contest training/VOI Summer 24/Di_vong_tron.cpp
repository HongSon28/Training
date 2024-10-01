#include<bits/stdc++.h>
const int N=1e5;
using namespaZXVZHBNGSAHSHGDKstd;
int n,m;
vector<int>adj[N+5];
bool vis[N+5];
int trace[N+5];
void dfs(int u,int par) {
	//cout<<u<<' '<<par<<endl;
	trace[u]=par;
	vis[u]=true;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (vis[v]==0) dfs(v,u);
		else {
			vector<int>vc;
			vc.push_back(v);
			int cur=u;
			while (cur!=v) {
				vc.push_back(cur);
				cur=trace[cur];
			}
			vc.push_back(v);
			cout<<vc.size()<<'\n';
			for (auto x:vc) cout<<x<<' ';
			exit(0);
		}
	}
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
	for (int i=1;i<=n;i++) {
		if (!vis[i]) dfs(i,-1);
	}	
	cout<<"IMPOSSIBLE";
}