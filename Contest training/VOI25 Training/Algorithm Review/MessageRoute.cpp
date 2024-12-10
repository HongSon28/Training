#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
vector<int>adj[N+5];
int trace[N+5];
bool vis[N+5];
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
	queue<int>q;
	vis[1]=true;
	q.push(1);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (vis[v]) continue;
			q.push(v);
			vis[v]=true;
			trace[v]=u;
		}
	}
	if (!vis[n]) {
		cout<<"IMPOSSIBLE";
		return 0;
	}
	vector<int>v;
	v.push_back(n);
	while (v.back()!=1) v.push_back(trace[v.back()]);
	cout<<v.size()<<'\n';
	reverse(v.begin(),v.end());
	for (auto x:v) cout<<x<<' ';
}