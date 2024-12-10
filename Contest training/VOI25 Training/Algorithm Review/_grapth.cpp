#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m;
vector<vector<int>>adj(N+5);
bool joint[N+5];
int low[N+5],num[N+5];
int timer,bridge;
void dfs(int u,int par) {
	int child=0;
	num[u]=low[u]=++timer;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (!num[v]) {
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if (low[v]==num[v]) bridge++;
			child++;
			if (u==par) {
				if (child>1) joint[u]=true;
			} else if (low[v]>=num[u]) joint[u]=true;
		} else low[u]=min(low[u],num[v]);
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
    	if (!num[i]) dfs(i,i);
    }
    int cnt=0;
    for (int i=1;i<=n;i++) cnt+=joint[i];
    cout<<cnt<<' '<<bridge;
}
