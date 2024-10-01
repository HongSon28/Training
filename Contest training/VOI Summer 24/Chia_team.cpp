#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<int>adj[N+5];
int col[N+5];
queue<int>q;
void bfs() {
	while (!q.empty()) {
		int u=q.front();
		int c=col[u];
		q.pop();
		for (auto v:adj[u]) {
			if (!col[v]) {
				col[v]=3-col[u];
				q.push(v);
			} else if (col[v]==col[u]) {
				cout<<"IMPOSSIBLE";
				exit(0);
			}
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
		if (!col[i]) {
			col[i]=1;
			q.push(i);
			bfs();
		}
	}
	for (int i=1;i<=n;i++) cout<<col[i]<<' ';
}