#include<bits/stdc++.h>
using namespace std;
const int N=1e5,SZ=316,LG=20;
int n,q;
vector<int>adj[N+5];
int d[N+5];
pair<int,int>qu[N+5];
bool red[N+5];
int h[N+5],fai[N+5],m;
int euler[N*3+5];
pair<int,int>rmq[N*3+5][LG+5];
void dfs(int u,int par) {
	h[u]=h[par]+1;
	euler[++m]=u;
	if (!fai[u]) fai[u]=m;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		euler[++m]=u;
	}
}
void prep() {
	for (int i=1;i<=m;i++) rmq[i][0]={h[euler[i]],euler[i]};
	for (int i=1;(1<<i)<=m;i++) {
		for (int j=1;j+(1<<i)-1<=m;j++) rmq[j][i]=min(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
	}
}
int lca(int l,int r) {
	if (l>r) swap(l,r);
	int k=__lg(r-l+1);
	pair<int,int>temp=min(rmq[l][k],rmq[r-(1<<k)+1][k]);
	return temp.second;
}
int dist(int u,int v) {
	int k=lca(fai[u],fai[v]);
	return h[u]+h[v]-2*h[k];
}
bool vis[N+5];
void bfs() {
	queue<pair<int,int>>q;
	for (int i=1;i<=n;i++) {
		if (red[i]) q.push({i,0});
		vis[i]=red[i];
	}
	while (!q.empty()) {
		int u=q.front().first,du=q.front().second;
		q.pop();
		d[u]=du;
		for (auto v:adj[u]) {
			if (vis[v]) continue;
			vis[v]=true;
			q.push({v,du+1});
		}
	}
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
    dfs(1,0);
    prep();
    for (int i=1;i<=q;i++) cin>>qu[i].first>>qu[i].second;
    red[1]=true;
    for (int i=1;i<=q;i+=SZ) {
    	bfs();
    	int j=min(q,i+SZ-1);
    	for (int t=i;t<=j;t++) {
    		if (qu[t].first==1) {
    			red[qu[t].second]=true;
    			continue;
    		}
    		int res=d[qu[t].second];
    		for (int k=i;k<t;k++) 
    			if (qu[k].first==1) res=min(res,dist(qu[t].second,qu[k].second));
    		cout<<res<<'\n';
    	}
    }
}