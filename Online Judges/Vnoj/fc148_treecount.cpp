#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<int,int>a[N+5];
int in[N+5],out[N+5];
int bit[N+5];
int t=1;
vector<vector<int>>adj(N+5);
int res[N+5];
void dfs(int u,int par) {
	in[u]=t;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
	}
	out[u]=t;
	t++;
}
int get(int idx) {
	int ans=0;
	while (idx>0) {
		ans+=bit[idx];
		idx-=idx&(-idx);
	}
	return ans;
}
void update(int idx) {
	while (idx<=n) {
		bit[idx]++;
		idx+=idx&(-idx);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i].first;
		a[i].second=i;
	}	
	sort(a+1,a+1+n);
	for (int i=2;i<=n;i++) {
		int p;
		cin>>p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}
	dfs(1,0);
	for (int i=n;i>=1;i--) {
		res[a[i].second]=get(out[a[i].second])-get(in[a[i].second]-1);
		update(out[a[i].second]);
	}
	for (int i=1;i<=n;i++) cout<<res[i]<<'\n';	
}