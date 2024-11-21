#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m,q;
vector<pair<int,int>>adj[N+5];
namespace sub1{
	const int M=8000;
	bool check() {
		return (n<=500&&m<=8000&&q<=100000);
	}
	bool vis[N+5][N+5];
	bool block[M+5];
	int res[N+5][N+5];
	void bfs(int s) {
		queue<int>q;
		for (int i=1;i<=n;i++) vis[s][i]=false;
		vis[s][s]=true;
		q.push(s);
		while (!q.empty()) {
			int u=q.front();
			q.pop();
			for (auto [v,id]:adj[u]) {
				if (!vis[s][v]&&!block[id]) {
					vis[s][v]=true;
					q.push(v);
				}
			}
		}
	}
	long long b=2e5,mod=1e9+7;
	void solve() {
		for (int i=1;i<=n;i++) 
			for (int j=1;j<=n;j++) res[i][j]=m+1;
		for (int i=0;i<=m;i++) {
			block[i]=true;
			for (int j=1;j<=n;j++) bfs(j);
			block[i]=false;
			for (int j=1;j<=n;j++) {
				for (int k=j;k<=n;k++) {
					if (!vis[j][k]||!vis[k][j]) {
						res[j][k]=min(res[j][k],i);
						res[k][j]=min(res[k][j],i);
					}
				}
			}
		}
		vector<int>v;
		if (q==0) {
			for (int i=1;i<=n;i++) {
				for (int j=i;j<=n;j++) {
					v.push_back(res[i][j]);
					//cout<<i<<' '<<j<<' '<<res[i][j]<<endl;
				}
			}
		} else {
			while (q--) {
				int x,y;
				cin>>x>>y;
				v.push_back(res[x][y]);
			}
		}
		reverse(v.begin(),v.end());
		long long cur=1,ans=0;
		for (auto x:v) {
			ans+=x*cur%mod;
			ans%=mod;
			cur*=b;
			cur%=mod;
		}
		cout<<ans;
	}
};
namespace sub2{
	const int M=8000;
	bool vis[N+5][N+5];
	int res[N+5][N+5];
	void bfs(int s) {
		queue<int>q;
		for (int i=1;i<=n;i++) vis[s][i]=false;
		vis[s][s]=true;
		q.push(s);
		while (!q.empty()) {
			int u=q.front();
			q.pop();
			for (auto [v,id]:adj[u]) {
				if (!vis[s][v]) {
					vis[s][v]=true;
					q.push(v);
				}
			}
		}
	}
	long long b=2e5,mod=1e9+7;
	void solve() {
		for (int j=1;j<=n;j++) bfs(j);
		for (int j=1;j<=n;j++) {
			for (int k=j;k<=n;k++) {
				if (vis[j][k]&&vis[k][j]) res[j][k]=res[k][j]=m+1;
			}
		}
		vector<int>v;
		if (q==0) {
			for (int i=1;i<=n;i++) {
				for (int j=i;j<=n;j++) {
					v.push_back(res[i][j]);
					//cout<<i<<' '<<j<<' '<<res[i][j]<<endl;
				}
			}
		} else {
			while (q--) {
				int x,y;
				cin>>x>>y;
				v.push_back(res[x][y]);
			}
		}
		reverse(v.begin(),v.end());
		long long cur=1,ans=0;
		for (auto x:v) {
			ans+=x*cur%mod;
			ans%=mod;
			cur*=b;
			cur%=mod;
		}
		cout<<ans;
	}
};
int main() {
	freopen("CONNECT.INP","r",stdin);
	freopen("CONNECT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back({v,i});
    }
    cin>>q;
    if (sub1::check()) sub1::solve();
    else sub2::solve();
}