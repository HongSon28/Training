#include<bits/stdc++.h>
using namespace std;
const int N=3000,LG=12;
int n,q;
vector<pair<int,int>>adj[N+5];
int d[N+5],s[N+5],cur,fai[N+5];
vector<int>euler;
pair<int,int>rmq[N+5][LG+5];
void dfs(int u,int par) {
	cur++;
	if (!fai[u]) fai[u]=cur;
	d[u]=d[par]+1;
	euler.push_back(u);
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		s[v]=s[u]+w;
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
}
int lca(int l,int r) {
	if (l>r) swap(l,r);
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
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    euler.push_back(0);
    dfs(1,0);
    prep();
    while (q--) {
    	int u,v;
    	cin>>u>>v;
    	int k=lca(fai[u],fai[v]);
    	cout<<s[u]+s[v]-2*s[k]<<'\n';
    }
}
