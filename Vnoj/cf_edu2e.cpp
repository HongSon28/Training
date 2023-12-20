#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long c[N+5],res[N+5],mx[N+5];
vector<vector<int>>adj(N+5);
map<int,long long>mp[N+5];
void dfs(int u,int par) {
	mp[u][c[u]]++;
	res[u]=c[u];
	mx[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		if (mp[u].size()<mp[v].size()) {
			swap(mp[u],mp[v]);
			res[u]=res[v];
			mx[u]=mx[v];
		}
		for (auto i=mp[v].begin();i!=mp[v].end();i++) {
			mp[u][i->first]+=i->second;
			int val=mp[u][i->first];
			if (val>mx[u]) {
				mx[u]=val;
				res[u]=i->first;
			} else if (val==mx[u]) res[u]+=i->first;
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