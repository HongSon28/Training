#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=18;
int n,q;
vector<int>adj[N+5];
int d[N+5],cur,fai[N+5];
vector<int>euler;
pair<int,int>rmq[N+5][LG+5];
int mn[N+5][LG+5],mx[N+5][LG+5];
void dfs(int u,int par) {
	cur++;
	if (!fai[u]) fai[u]=cur;
	d[u]=d[par]+1;
	euler.push_back(u);
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		euler.push_back(u);
		cur++;
	}
}
void prep() {
	int m=euler.size()-1;
	for (int i=1;i<=m;i++) rmq[i][0]={d[euler[i]],euler[i]};
	for (int i=1;(1<<i)<=m;i++) {
		for (int j=1;j+(1<<i)-1<=m;j++) rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	}
	for (int i=1;i<=n;i++) mn[i][0]=mx[i][0]=fai[i];
	for (int i=1;(1<<i)<=n;i++) {
		for (int j=1;j+(1<<i)-1<=m;j++) {
			mn[j][i]=min(mn[j][i-1],mn[j+(1<<(i-1))][i-1]);
			mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
		}
	}
}
int getmin(int l,int r) {
	int k=__lg(r-l+1);
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
int getmax(int l,int r) {
	int k=__lg(r-l+1);
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
int get(int l,int r) {
	int k=__lg(r-l+1);
	pair<int,int>t=min(rmq[l][k],rmq[r-(1<<k)+1][k]);
	return t.second;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    euler.push_back(0);
    dfs(1,0);
    prep();
    while (q--) {
    	int u,v;
    	cin>>u>>v;
    	cout<<get(getmin(u,v),getmax(u,v))<<'\n';
    }
}