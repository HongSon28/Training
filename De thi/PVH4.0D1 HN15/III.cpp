#include<bits/stdc++.h>
using namespace std;
const int N=8e4,M=350000;
int sub,t,n,m;
struct edge{
	int v,id;
	char dir;
};
vector<vector<edge>>adj(N+5);
char dir[M+5];
bool vis[N+5];
long long dp[N+5],res,cur;
void dfs(int u) {
	for (auto e:adj[u]) {
		int v=e.v,id=e.id;
		char c=e.dir;
		if (dir[id]!=' ') continue;
		dir[id]=c;
		if (vis[v]) continue;
		vis[v]=true;
		dfs(v);
	}
}
void dfs_calc(int u) {
	for (auto e:adj[u]) {
		int v=e.v,id=e.id;
		char c=e.dir;
		if (dir[id]!=c) continue;
		dfs_calc(v);
		dp[u]+=dp[v]+1;
	}
}
void solve_tree() {
	int leaf;
	for (int i=1;i<=n;i++) dp[i]=0;
	for (int i=1;i<=n;i++) {
		if (adj[i].size()==1) {
			vis[i]=true;
			dfs(i);
			leaf=i;
			break;
		}
	}
	dfs_calc(leaf);
	for (int i=1;i<=n;i++) res+=dp[i];
	cout<<res<<' ';
	for (int i=1;i<=m;i++) cout<<dir[i];
	cout<<'\n';
}
void dfs_calc2(int u) {
	for (auto e:adj[u]) {
		int v=e.v,id=e.id;
		char c=e.dir;
		if (dir[id]!=c||vis[v]) continue;
		vis[v]=true;
		dfs_calc2(v);
		cur++;
	}
}
void solve() {
	int leaf=1;
	for (int i=1;i<=n;i++) {
		if (adj[i].size()==1) {
			leaf=i;
			break;
		}
	}
	vis[leaf]=true;
	dfs(leaf);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) vis[j]=false;
		vis[i]=true;
		dfs_calc2(i);
		res+=cur;
		cur=0;
	}
	cout<<res<<' ';
	for (int i=1;i<=m;i++) cout<<dir[i];
	cout<<'\n';
}
 int main() {
 	freopen("III.INP","r",stdin);
	freopen("III.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>sub>>t;
	while (t--) {
		cin>>n>>m;
		for (int i=1;i<=n;i++) {
			dir[i]=' ';
			vis[i]=false;
		}
		adj.clear();
		adj.resize(n+1);
		res=0;
		for (int i=1;i<=m;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back({v,i,'F'});
			adj[v].push_back({u,i,'B'});
		}
		if (sub==3) solve_tree();
		else solve();
	}
}