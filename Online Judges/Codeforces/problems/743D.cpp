#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
vector<int>adj[N+5];
long long f[N+5],g[N+5],s[N+5],inf=1e18;
bool flag;
void dfs(int u,int par) {
	s[u]=a[u];
	f[u]=g[u]=-inf;
	long long mx1=-inf,mx2=-inf;
	int cnt=0;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		cnt++;
		f[u]=max(f[u],f[v]);
		s[u]+=s[v];
		g[u]=max(g[u],g[v]);
		g[u]=max(g[u],s[v]);
		mx2=max(mx2,g[v]);
		if (mx2>mx1) swap(mx2,mx1);
	}
	if (cnt>=2) flag=true;
	g[u]=max(g[u],s[u]);
	f[u]=max(f[u],mx1+mx2);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,0);
    if (!flag) cout<<"Impossible";
    else cout<<f[1];
}