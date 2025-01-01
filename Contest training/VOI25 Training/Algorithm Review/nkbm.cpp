#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,x,y,m;
vector<int>adj[N+5];
int res;
int vis[N+5],t;
int assigned[N+5];
bool dfs(int u) {
	if (vis[u]==t) return false;
	vis[u]=t;
	for (auto v:adj[u]) {
		if (!assigned[v]||dfs(assigned[v])) {
			assigned[v]=u;
			return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>x>>y>>m;
    n=x+y;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(x+v);
    	adj[x+v].push_back(u);
    }	
    for (int i=1;i<=n;i++) {
    	t++;
    	res+=dfs(i);
    }
    cout<<res/2;
}