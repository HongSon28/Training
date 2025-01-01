#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,s,t;
vector<int>adj[N+5];
int c[N+5][N+5],f[N+5][N+5],res,inf=1e9;
int trace[N+5];
void bfs() {
	queue<int>q;
	q.push(s);
	memset(trace,0,sizeof(trace));
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (trace[v]||c[u][v]==f[u][v]) continue;
			trace[v]=u;
			q.push(v);
		}
	}
}
void inc() {
	int delta=inf;
	int v=t;
	while (v!=s) {
		int u=trace[v];
		delta=min(delta,c[u][v]-f[u][v]);
		v=u;
	}
	res+=delta;
	v=t;
	while (v!=s) {
		int u=trace[v];
		f[u][v]+=delta;
		f[v][u]-=delta;
		v=u;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	cin>>c[u][v];
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    bfs();
    while (trace[t]) {
    	inc();
    	bfs();
    }
    cout<<res;
}