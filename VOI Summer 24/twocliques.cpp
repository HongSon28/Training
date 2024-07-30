#include<bits/stdc++.h>
using namespace std;
const int N=200;
int t,n;
int a[N+5][N+5];
vector<int>adj[N+5];
bool vis[N+5];
int col[N+5];
bool bfs(int s) {
	vis[s]=true;
	col[s]=1;
	queue<int>q;
	q.push(s);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto v:adj[u]) {
			if (!vis[v]) {
				vis[v]=true;
				col[v]=3-col[u];
				q.push(v);
			} else {
				if (col[v]!=3-col[u]) return false;
			}
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		bool flag=true;
		for (int i=1;i<=n;i++) {
			adj[i].clear();
			vis[i]=false;
			col[i]=0;
			for (int j=1;j<=n;j++) cin>>a[i][j];
		}
		for (int i=1;i<n;i++) {
			for (int j=i+1;j<=n;j++) {
				if (a[i][j]) continue;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
		for (int i=1;i<=n;i++) {
			if (vis[i]) continue;
			if (!bfs(i)) {
				flag=false;
				break;
			}
		}
		if (flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}