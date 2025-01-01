#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
vector<int>adj[N+5];
int c[N+5],col[N+5];
int cnt[N+5],cur;
int sz[N+5];
int sum[N+5],m;
vector<int>res;
void pre_dfs(int u,int par) {
	sz[u]=1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		pre_dfs(v,u);
		sz[u]+=sz[v];
	}
}
void add(int t) {
	if (cnt[t]==0) cur++;
	cnt[t]++;
}
void del(int t) {
	if (cnt[t]==1) cur--;
	cnt[t]--;
}
void update(int u,int par,int delta) {
	if (delta==1) add(c[u]);
	else del(c[u]);
	for (auto v:adj[u]) {
		if (v!=par) update(v,u,delta);
	}
}
bool solve(int u,int par) {
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (col[v]==-1) return false;
	}
	int temp=m;
	for (auto v:adj[u]) {
		if (v==par) continue;
		sum[col[v]]-=sz[v];
		if (sum[col[v]]==0) temp--;
	}
	sum[c[u]]--;
	if (sum[c[u]]==0) temp--;
	for (auto v:adj[u]) {
		if (v==par) continue;
		sum[col[v]]+=sz[v];
	}
	sum[c[u]]++;
	//cout<<u<<' '<<m<<' '<<temp<<endl;
	return (temp<=1);
}
void dfs(int u,int par) {
	int big=-1;
	for (auto v:adj[u]) {
		if (v==par) continue;
		if (big==-1||sz[v]>sz[big]) big=v;
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
	add(c[u]);
	if (cur>1) col[u]=-1;
	else col[u]=c[u];
	if (solve(u,par)) res.push_back(u);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    for (int i=1;i<=n;i++) {
    	cin>>c[i];
    	sum[c[i]]++;
    	if (sum[c[i]]==1) m++;
    }
    pre_dfs(1,0);
    dfs(1,0);
    if (res.empty()) {
    	cout<<"NO";
    	return 0;
    }
    cout<<"YES"<<'\n';
    sort(res.begin(),res.end());
    for (auto x:res) cout<<x<<' ';
}