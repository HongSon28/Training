#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int m,n,q;
char c[N+5][N+5];
int par[N*N+5];
char col[N*N+5];
int res,cnt;
forward_list<pair<int,int>>adj[N*N+5];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int find_root(int u) {
	if (par[u]<0) return u;
	return par[u]=find_root(par[u]);
}
void Union(int x1,int y1,int x2,int y2) {
	int u=(x1-1)*n+y1,v=(x2-1)*n+y2;
	if ((u=find_root(u))==(v=find_root(v))) return;
	if (col[u]!=col[v]) return;
	cnt--;
	if (par[v]<par[u]) swap(u,v);
	adj[u].splice_after(adj[u].before_begin(),adj[v]);
	par[u]+=par[v];
	par[v]=u;
	res=max(res,-par[u]);
}
int main() {
	freopen("FFILL.INP","r",stdin);
	freopen("FFILL.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>m>>n;
	cnt=m*n;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			cin>>c[i][j];
			for (int t=0;t<4;t++) {
				int x=dx[t]+i,y=dy[t]+j;
				if (x>=1&&y>=1&&x<=m&&y<=n) {
					adj[(i-1)*n+j].push_front({x,y});
					//cout<<(i-1)*n+j<<' '<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
				}
			}
			par[(i-1)*n+j]=-1;
			col[(i-1)*n+j]=c[i][j];
		}
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			for (int t=0;t<4;t++) {
				int x=dx[t]+i,y=dy[t]+j;
				if (x>=1&&y>=1&&x<=m&&y<=n) {
					if (c[x][y]==c[i][j]) {
						Union(x,y,i,j);
						//cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl;
					}
				}
			}
		}
	}
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++) {
			int u=find_root((i-1)*n+j);
			res=max(res,-par[u]);
		}
	}
	cin>>q;
	while (q--) {
		char ch;
		int i,j;
		cin>>ch>>i>>j;
		int u=find_root((i-1)*n+j);
		if (col[u]==ch||cnt==1) {
			cout<<cnt<<' '<<res<<'\n';
			continue;
		}
		col[u]=ch;
		vector<pair<int,int>>temp;
		for (auto p:adj[u]) temp.push_back(p);
		for (auto [x,y]:temp) {
			if (cnt==1) break;
			Union(i,j,x,y);
		}
		cout<<cnt<<' '<<res<<'\n';
	}
}