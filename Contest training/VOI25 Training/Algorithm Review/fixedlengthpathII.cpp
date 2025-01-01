#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k1,k2;
vector<int>adj[N+5];
bool del[N+5];
int child[N+5];
long long res;
void countchild(int u,int par) {
	child[u]=1;
	for (auto v:adj[u]) {
		if (v==par||del[v]) continue;
		countchild(v,u);
		child[u]+=child[v];
	}
}
int centroid(int u,int par,int sz) {
	for (auto v:adj[u]) {
		if (v==par||del[v]) continue;
		if (child[v]>sz/2) return centroid(v,u,sz);
	}
	return u;
}
int depth;
vector<int>cur;
void dfs(int u,int par,int d) {
	depth=max(depth,d);
	cur.push_back(d);
	for (auto v:adj[u]) {
		if (v!=par&&!del[v]) dfs(v,u,d+1);
	}
}
int s[N+5],cnt[N+5];
void update(int root,int sz) {
	s[0]=1;
	for (auto v:adj[root]) {
		if (del[v]) continue;
		depth=0;
		cur.clear();
		dfs(v,root,1);
		for (int i=0;i<=depth;i++) cnt[i]=0;
		for (auto x:cur) {
			if (x<k1) res+=s[k1-x]-s[k2+1-x];
			else if (x<=k2) res+=s[0]-s[k2+1-x];
			cnt[x]++;
		}
		int tmp=0;
		for (int i=depth;i>=0;i--) {
			tmp+=cnt[i];
			s[i]+=tmp;
		}
	}
	for (int i=1;i<=sz;i++) s[i]=0;
}
void solve(int u) {
	countchild(u,0);
	int n=child[u];
	if (n<=k1) return;
	int root=centroid(u,0,n);
	update(root,n);
	del[root]=true;
	for (auto v:adj[root]) {
		if (!del[v]) solve(v);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k1>>k2;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    solve(1);
    cout<<res;
}