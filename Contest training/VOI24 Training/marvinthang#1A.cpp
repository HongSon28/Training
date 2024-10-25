#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m,sx,sy,ex,ey;
char c[N+5][N+5];
int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
char ch[]={'v','>','<','^'};
struct dat{
	int x,y,d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int d[N+5][N+5],inf=1e9;
int trace[N+5][N+5];
char res[N+5][N+5];
void tr(int x,int y) {
	if (x==sx&&y==sy) return;
	int t=trace[x][y];
	int u=x-dx[t],v=y-dy[t];
	if (res[u][v]!='o') res[u][v]=ch[t];
	tr(u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			d[i][j]=inf;
			cin>>c[i][j];
			res[i][j]=c[i][j];
			if (c[i][j]=='o') {
				sx=i; sy=j;
				d[i][j]=0;
			} else if (c[i][j]=='x') {
				ex=i; ey=j;
			}
		}
	}
	pq.push({sx,sy,0});
	while (!pq.empty()) {
		auto [u,v,du]=pq.top();
		pq.pop();
		if (du!=d[u][v]) continue;
		for (int i=0;i<4;i++) {
			int x=u+dx[i],y=v+dy[i];
			int w=1;
			if (c[u][v]=='o'||c[u][v]==ch[i]) w=0;
			if (d[x][y]>d[u][v]+w) {
				d[x][y]=d[u][v]+w;
				pq.push({x,y,d[x][y]});
				trace[x][y]=i;
			}
		}
	}
	cout<<d[ex][ey]<<'\n';
	tr(ex,ey);
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) cout<<res[i][j];
		cout<<'\n';
	}
}