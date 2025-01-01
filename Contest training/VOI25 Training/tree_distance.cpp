#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,k;
vector<int>adj[N+5];
long long res;
bool del[N+5];
int child[N+5];
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
vector<int>cur,temp;
long long cnt[N+5];
void dfs(int u,int par,int d) {
	if (d>k) return;
	temp.push_back(d);
	res+=cnt[k-d];
	for (auto v:adj[u]) {
		if (v!=par&&!del[v]) dfs(v,u,d+1);
	}
}
void update(int root,int sz) {
	if (sz<=k) return;
	cnt[0]++;
	cur.clear();
	cur.push_back(0);
	for (auto v:adj[root]) {
		if (!del[v]) {
			temp.clear();
			dfs(v,root,1);
			for (auto x:temp) {
				cnt[x]++;
				cur.push_back(x);
			}
		}
	} 
	for (auto x:cur) cnt[x]--;
	//cout<<root<<' '<<res<<endl;
}
void solve(int u) {
	countchild(u,0);
	int n=child[u];
	if (n<=k) return;
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
    cin>>n>>k;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    solve(1);
    cout<<res;
}