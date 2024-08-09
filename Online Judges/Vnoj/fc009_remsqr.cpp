#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
char c[N+5][N+5];
bool vis[N+5][N+5];
int res;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void dfs(int u,int v) {
	vis[u][v]=true;
	for (int i=0;i<4;i++) {
		int x=u+dx[i],y=v+dy[i];
		if (x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y]&&c[x][y]=='#') dfs(x,y);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) 
			cin>>c[i][j];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (c[i][j]=='#'&&!vis[i][j]) {
				res++;
				dfs(i,j);
			}
		}
	}
	cout<<res;
}