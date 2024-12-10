#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<int>adj[N+5];
int deg[N+5];
queue<int>q;
vector<int>res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		deg[v]++;
	}
	for (int i=1;i<=n;i++) {
		if (!deg[i]) q.push(i);
	}
	while (!q.empty()) {
		int u=q.front();
		res.push_back(u);
		q.pop();
		for (auto v:adj[u]) {
			deg[v]--;
			if (deg[v]==0) q.push(v);
		}
	}
	if (res.size()!=n) {
		cout<<"IMPOSSIBLE";
		return 0;
	}
	for (auto x:res) cout<<x<<' '; 
}