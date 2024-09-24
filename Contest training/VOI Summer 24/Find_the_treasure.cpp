#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
vector<int>adj[N+5];
queue<int>q;
int vis[N+5],trace[N+6];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			vis[i]=trace[i]=-1;
			adj[i].clear();
		}
		vis[n]=0;
		for (int i=1;i<n;i++) {
			int m,x;
			cin>>m;
			while (m--) {
				cin>>x;
				adj[x].push_back(i);
			}
		}
		while (!q.empty()) q.pop();
		q.push(n);
		while (!q.empty()) {
			int u=q.front();
			q.pop();
			for (auto v:adj[u]) {
				if (vis[v]==-1) {
					vis[v]=vis[u]+1;
					q.push(v);
					trace[v]=u;
				} else if (vis[v]==vis[u]+1) trace[v]=min(trace[v],u);
			}
		}
		if (vis[1]==-1) {
			cout<<-1<<'\n'<<'\n';
			continue;
		}
		cout<<vis[1]<<'\n';	
		int cur=1;
		while (vis[1]--) {
			cout<<cur<<' ';
			cur=trace[cur];
		}
		cout<<'\n'<<'\n';
	}
}