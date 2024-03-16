#include<bits/stdc++.h>
using namespace std;
const int N=500,M=1e6;
int n,m;
int a[N+5][N+5];
pair<int,int> par[N+5][N+5];
bool vis[N+5][N+5],used[M+5];
queue<pair<int,int>>q;
int res;
void add(int x,int y,int u,int v) {
	if (x<1||u<1||y<1||v<1||x>n||u>n||y>m||v>m) return;
	if (par[x][y]!=make_pair(u,v)) return;
	used[a[x][y]]=true;
	if (vis[u][v]) return;
	vis[u][v]=true;
	q.push({u,v});
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=(n*m-1)/2;i++) {
		int x,y,u,v;
		cin>>x>>y>>u>>v;
		a[x][y]=i;
		a[u][v]=i;
		par[x][y]={u,v};
		par[u][v]={x,y};
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			if (!a[i][j])
				q.push({i,j});
	while (!q.empty()) {
		int u=q.front().first,v=q.front().second;
		q.pop();
		add(u-1,v,u-2,v);
		add(u+1,v,u+2,v);
		add(u,v+1,u,v+2);
		add(u,v-1,u,v-2);	
	}
	for (int i=1;i<=(n*m-1)/2;i++) res+=used[i];
	cout<<res;		
}