#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
int c[N+5];
vector<int>adj[N+5];
vector<pair<int,int>>query[N+5];
int res[N+5];
int sz[N+5];
void pre_dfs(int u,int par) {
	sz[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		pre_dfs(v,u);
		sz[v]+=sz[u];
	}
}
int cur,cnt[N+5];
struct Fenwick{
	int bit[N+5];
	void update(int idx,int val) {
		while (idx>0) {
			bit[idx]+=val;
			idx-=(idx&(-idx));
		}
	}
	int get(int idx) {
		int ans=0;
		while (idx<=n) {
			ans+=bit[idx];
			idx+=(idx&(-idx));
		}
		return ans;
	}
} tree;
void upd(int col,int val) {
	tree.update(cnt[col],-1);
	cnt[col]+=val;
	tree.update(cnt[col],1);
}
void update(int u,int par,int delta) {
	upd(c[u],delta);
	for (auto v:adj[u]) {
		if (v!=par) update(v,u,delta);
	}
}
void dfs(int u,int par) {
	int big=-1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (big==-1||sz[big]<sz[v]) big=v;
	}
	for (auto v:adj[u]) {
		if (v==par||v==big) continue;
		dfs(v,u);
		update(v,u,-1);
	}
	if (big!=-1) dfs(big,u);
	for (auto v:adj[u]) {
		if (v==par||v==big) continue;
		update(v,u,1);
	}
	upd(c[u],1);
	for (auto [k,id]:query[u]) res[id]=tree.get(k);
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
	cin>>q;
	for (int i=1;i<=q;i++) {
		int v,k;
		cin>>v>>k;
		query[v].push_back({k,i});
	}
	pre_dfs(1,0);
	dfs(1,0);
	for (int i=1;i<=q;i++) cout<<res[i]<<' ';	
}