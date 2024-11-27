#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
char c[N+5][N+5];
int d[N+5][N+5],inf=1e9,res=inf;
deque<pair<int,int>>q;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>c[i][j];
			d[i][j]=inf;
		}
	}
	for (int i=1;i<=m;i++) {
		if (c[1][i]=='.') {
			q.push_back({1,i});
			d[1][i]=1;
		} else if (c[1][i]=='#') {
			q.push_front({1,i});
			d[1][i]=0;
		}
	}
	for (int i=2;i<=n;i++) {
		if (c[i][m]=='.') {
			q.push_back({i,m});
			d[i][m]=1;
		} else if (c[i][m]=='#') {
			q.push_front({i,m});
			d[i][m]=0;
		}
	}
	while (!q.empty()) {
		int u=q.front().first,v=q.front().second;
		if (u==n||v==1) res=min(res,d[u][v]);
		q.pop_front();
		for (int i=0;i<8;i++) {
			int x=u+dx[i],y=v+dy[i],w;
			if (x>=1&&y>=1&&x<=n&&y<=m) {
				if (c[x][y]=='#') w=0;
				else if (c[x][y]=='.') w=1;
				else continue;
				if (d[x][y]>d[u][v]+w) {
					d[x][y]=d[u][v]+w;
					if (w==0) q.push_front({x,y});
					else q.push_back({x,y});
				}
			}
		}
	}
	if (res==inf) cout<<-1;
	else cout<<res;
}