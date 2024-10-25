#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int c[N+5];
vector<int>adj[N+5];
map<int,int>mp[N+5];
long long res[N+5],mx[N+5];
void dfs(int u,int par) {
	mp[u][c[u]]++;
	res[u]=c[u];
	mx[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		if (mp[u].size()<mp[v].size()) {
			swap(mp[u],mp[v]);
			mx[u]=mx[v];
			res[u]=res[v];
		}
		for (auto i=mp[v].begin();i!=mp[v].end();i++) {
			int col=i->first;
			mp[u][col]+=i->second;
			if (mp[u][col]==mx[u]) res[u]+=col;
			else if (mp[u][col]>mx[u]){
				mx[u]=mp[u][col];
				res[u]=col;
			}
		}
		mp[v].clear();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}