#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
char c[N+5][N+5];
struct dat{
	int x,y,d;
	bool operator < (const dat &other) const {
		return d>other.d;
	}
};
priority_queue<dat>pq;
int d[N+5][N+5],inf=1e9;
int dx[]={-1,-1,1,1};
int dy[]={1,-1,1,-1};
int cost(int u,int v,int x,int y) {
	if (u>x) {
		swap(u,x);
		swap(v,y);
	}
	if (v>y) return ((int)c[u][v-1]!=47);
	return ((int)c[u][v]==47);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>c[i][j];
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++)
			d[i][j]=inf;
	d[0][0]=0;
	pq.push({0,0,0});
	while (!pq.empty()) {
		dat t=pq.top();
		pq.pop();
		int x=t.x,y=t.y,du=t.d;
		if (du!=d[x][y]) continue;
		for (int i=0;i<4;i++) {
			int u=x+dx[i],v=y+dy[i];
			if (u>=0&&v>=0&&u<=n&&v<=m) {
				if (d[x][y]+cost(u,v,x,y)<d[u][v]) {
					d[u][v]=d[x][y]+cost(u,v,x,y);
					//cout<<u<<' '<<v<<' '<<d[u][v]<<endl;
					pq.push({u,v,d[u][v]});
				}
			}
		}
	}
	if (d[n][m]==inf) cout<<"NO SOLUTION";
	else cout<<d[n][m];
}