#include<bits/stdc++.h>
using namespace std;
int m,n,x,y;
int a[21][21];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int d[21][21];
int main() {
	freopen("DDMECUNG.INP","r",stdin);
	freopen("DDMECUNG.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>x>>y;
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>a[i][j];
    		d[i][j]=-1;
    	}
    }	
    queue<pair<int,int>>q;
	q.push({x,y});
	d[x][y]=0;
	while (!q.empty()) {
		int u=q.front().first,v=q.front().second;
		q.pop();
		if (u==1||v==1||u==m||v==n) {
			cout<<d[u][v];
			return 0;
		}
		for (int i=0;i<4;i++) {
			int tx=u+dx[i],ty=v+dy[i];
			if (tx>=1&&ty>=1&&tx<=m&&ty<=n&&d[tx][ty]==-1&&a[tx][ty]==0) {
				d[tx][ty]=d[u][v]+1;
				q.push({tx,ty});
			}
		}
	}
}