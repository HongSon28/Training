#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,m,p;
namespace sub4{
	vector<int>adj[N+5];
	int col[N+5],dp[N+5];
	bool dfs(int u) {
		col[u]=1;
		for (auto v:adj[u]) {
			if (col[v]==0) {
				if (dfs(v)) return true;
			} else if (col[v]==1) return true;
		}
		col[u]=2;
		return false;
	} 
	int f(int u) {
		if (dp[u]!=-1) return dp[u];
		dp[u]=0;
		for (auto v:adj[u]) {
			dp[u]=max(dp[u],f(v)+1);
		}
		return dp[u];
	}
	void solve() {
		for (int i=1;i<=n;i++) {
			adj[i].clear();
			col[i]=0;
			dp[i]=-1;
		}
		for (int i=1;i<=p;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
		}
		for (int i=1;i<=n;i++) {
			if (!col[i]&&dfs(i)) {
				cout<<-1<<'\n';
				return;
			}
		}
		int res=0;
		for (int i=1;i<=n;i++) res=max(res,f(i));
		cout<<res<<'\n';
	}
}
namespace sub5{
	vector<int>adj[N+5];
	bool vis[N+5];
	int f[N+5],g[N+5];
	bool dfs(int u,int par) {
		bool vispar=false;
		vis[u]=true;
		for (auto v:adj[u]) {
			if (v==par&&!vispar) {
				vispar=true;
				continue;
			} 
			if (vis[v]) return true;
			if (dfs(v,u)) return true;
		}
		return false;
	}
	void dfs2(int u,int par) {
		g[u]=0;
		int mx1=0,mx2=0;
		for (auto v:adj[u]) {
			if (v==par) continue;
			dfs2(v,u);
			g[u]=max(g[u],g[v]+1);
			f[u]=max(f[u],f[v]);
			mx2=max(mx2,g[v]+1);
			if (mx2>mx1) swap(mx2,mx1);
		}
		f[u]=mx1+mx2;
	}
	void solve() {
		for (int i=1;i<=n;i++) {
			adj[i].clear();
			vis[i]=false;
		}
		for (int i=1;i<=m;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i=1;i<=n;i++) {
			if (!vis[i]&&dfs(i,0)) {
				cout<<-1;
				return;
			}
		}
		dfs2(1,0);
		cout<<f[1]<<'\n';
	}
}
namespace sub3{
	int vis[N+5];
	vector<pair<int,int>>adj[N+5];
	int inf=1e9;
	int dfs(int u,int par) {
		bool vispar=false;
		vis[u]=1;
		int mx=0;
		for (auto t:adj[u]) {
			int v=t.first,type=t.second;
			if (v==par&&!vispar) {
				vispar=true;
				continue;
			}
			if (vis[v]==2) continue;
			if (vis[v]==1) return inf;
			if (type==1) mx=max(mx,dfs(v,u)+1);
			else mx=max(mx,dfs(v,0)+1);
			if (mx>=inf) break;
		}
		vis[u]=2;
		return mx;
	}
	void solve() {
		for (int i=1;i<=n;i++) {
			adj[i].clear();
		}
		for (int i=1;i<=m;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back({v,1});
			adj[v].push_back({u,1});
		}
		for (int i=1;i<=p;i++) {
			int u,v;
			cin>>u>>v;
			adj[u].push_back({v,2});
		}
		int res=0;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) vis[j]=0;
			res=max(res,dfs(i,0));
			if (res>=inf) {
				cout<<-1<<'\n';
				return;
			}
		}
		cout<<res<<'\n';
	}
}
int main() {
	freopen("FAKERFMVP.INP","r",stdin);
	freopen("FAKERFMVP.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m>>p;
    	if (m==0) sub4::solve();
    	else if (p==0) sub5::solve();
    	else sub3::solve();
    }
}