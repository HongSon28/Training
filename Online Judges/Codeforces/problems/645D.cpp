#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
pair<int,int>p[N+5];
int res=-1;
vector<int>adj[N+5];
int f[N+5];
void dfs(int u) {
	f[u]=1;
	for (auto v:adj[u]) {
		if (!f[v]) dfs(v);
		f[u]=max(f[u],f[v]+1);
	}
}
bool check(int k) {
	for (int i=1;i<=n;i++) {
		adj[i].clear();
		f[i]=0;
	}
	for (int i=1;i<=k;i++) adj[p[i].first].push_back(p[i].second);
	for (int i=1;i<=n;i++) {
		if (!f[i]) dfs(i);
	}
	for (int i=1;i<=n;i++) {
		if (f[i]==n) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>p[i].first>>p[i].second;
    int lo=n-1,hi=m;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<res;
}