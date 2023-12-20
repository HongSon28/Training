#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<vector<pair<int,int>>>adj(N+5);
int d[N+5];
bool vis[N+5];
int res,cnt;
void dfs(int u) {
	vis[u]=true;
	if (d[u]%2==1) cnt++;
	for (auto [v,c]:adj[u]) {
		if (c==1&&!vis[v]) dfs(v);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v,c;
    	cin>>u>>v>>c;
    	adj[u].push_back({v,c});
    	adj[v].push_back({u,c});
    	if (c==1) {
    		d[u]++;
    		d[v]++;
    	}
    }
    for (int i=1;i<=n;i++) {
    	if (!vis[i]) {
    		cnt=0;
    		dfs(i);
    		res+=cnt/2;
    	}
    }
    cout<<res;
}