#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
int a[N+5];
vector<int>adj[N+5];
int c[2][N+5],l[2][N+5];
int root0=-1,root1=-1,res;
bool dfs(int u,int par,int col) {
	bool p=(a[u]==col);
	for (auto v:adj[u]) {
		if (v==par) continue;
		bool t=dfs(v,u,col);
		if (t) res++;
		p|=t;
	}
	return p;
}
bool check(int u) {
	if (c[0][u]==c[0][0]-1&&c[1][u]==1) {
		if (l[1][u]==0&&l[0][u]==l[0][0]) return true; 
	} else if (c[1][u]==c[1][0]-1&&c[0][u]==1) {
		if (l[0][u]==0&&l[1][u]==l[1][0]) return true;
	}
	return false;
}
void dfs2(int u,int par) {
	c[a[u]][u]++; 
	if (adj[u].size()==1) l[a[u]][u]++;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs2(v,u);
		if (check(v)) {
			//cout<<v<<' ';
			cout<<res-1;
			exit(0);
		}
		c[0][u]+=c[0][v],c[1][u]+=c[1][v];
		l[0][u]+=l[0][v],l[1][u]+=l[1][v];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		char ch;
		cin>>ch;
		if (ch=='W') a[i]=1;
		if (a[i]&&root1==-1) root1=i;
		else if (!a[i]&&root0==-1) root0=i; 
	}
	for (int i=1;i<n;i++) {
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i=1;i<=n;i++) {
		c[a[i]][0]++;
		if (adj[i].size()==1) l[a[i]][0]++;
	}
	dfs(root0,0,0);
	dfs(root1,0,1);
	dfs2(1,0);
	cout<<res;
}