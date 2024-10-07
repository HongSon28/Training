#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,m;
int r,c,x,y;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int wg[]={0,0,0,1};
int d[N+5][N+5],inf=1e9+5;
struct dat{
	int x,y,w;
};
deque<dat>q;
char ch[N+5][N+5];
bool check(int x,int y) {
	return (x>=1&&y>=1&&x<=n&&y<=m&&ch[x][y]=='.');
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>r>>c>>x>>y;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) {
			cin>>ch[i][j];
			d[i][j]=inf;
		}
	q.push_back({r,c,0});
	d[r][c]=0;
	while (!q.empty()) {
		int u=q.front().x,v=q.front().y,w=q.front().w;
		q.pop_front();
		if (d[u][v]!=w) continue;
		for (int i=0;i<4;i++) {
			int x=u+dx[i],y=v+dy[i];
			if (check(x,y)&&d[x][y]>d[u][v]+wg[i]) {
				d[x][y]=d[u][v]+wg[i];
				if (wg[i]) q.push_back({x,y,d[x][y]});
				else q.push_front({x,y,d[x][y]});
			} 
		}
	}
	int res=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int l=d[i][j];
			int r=l+(j-c);
			//cout<<i<<' '<<j<<' '<<l<<' '<<r<<endl;
			res+=(l<=x&&r<=y);
		}
		//cout<<endl;
	}
	cout<<res;
}