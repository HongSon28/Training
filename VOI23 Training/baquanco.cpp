#include<bits/stdc++.h>
using namespace std;
const int N=30;
int n;
int a[N+5][N+5];
pair<int,int>pos[N*N+5];
int f[N+5][N+5][3][N*N+5],g[N+5][N+5][3][N*N+5],inf=1e9;
struct dat{
	int x,y,t,cur;
};
queue<dat>q;
int dx[]={1,1,-1,-1,2,2,-2,-2};
int dy[]={2,-2,2,-2,1,-1,1,-1};
bool valid(int x,int y,int u,int v,int t) {
	if (t==0) {
		int d1=abs(x-u),d2=abs(y-v);
		if (d1==2&&d2==1) return true;
		if (d1==1&&d2==2) return true;
		return false;
	}
	if (t==1) return (x==u||y==v);
	return (x-y==u-v||x+y==u+v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>a[i][j];
    		pos[a[i][j]]={i,j};
    		for (int k=1;k<=n*n;k++) f[i][j][0][k]=f[i][j][1][k]=f[i][j][2][k]=inf;
    	}
    }	
    int u=pos[1].first,v=pos[1].second;
    f[u][v][0][1]=f[u][v][1][1]=f[u][v][2][1]=0;
	q.push({u,v,0,1});
	q.push({u,v,1,1});
	q.push({u,v,2,1});
	while (!q.empty()) {
		int x=q.front().x,y=q.front().y,t=q.front().t,cur=q.front().cur;
		q.pop();
		for (int k=0;k<3;k++) {
			if (t==k) continue;
			if (f[x][y][k][cur]>f[x][y][t][cur]+1) {
				f[x][y][k][cur]=f[x][y][t][cur]+1;
				g[x][y][k][cur]=g[x][y][t][cur]+1;
				q.push({x,y,k,cur});
			} else if (f[x][y][k][cur]==f[x][y][t][cur]+1) {
				g[x][y][k][cur]=min(g[x][y][k][cur],g[x][y][t][cur]+1);
			}
		}
		int u,v;
		if (t==0) {
			for (int i=0;i<8;i++) {
				u=x+dx[i],v=y+dy[i];
				if (u<1||v<1||u>n||v>n) continue;
				if (cur+1==a[u][v]) {
					if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
						f[u][v][t][cur+1]=f[x][y][t][cur]+1;
						g[u][v][t][cur+1]=g[x][y][t][cur];
						q.push({u,v,t,cur+1});
					} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
						g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
					}
				} else {
					if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
						f[u][v][t][cur]=f[x][y][t][cur]+1;
						g[u][v][t][cur]=g[x][y][t][cur];
						q.push({u,v,t,cur});
					} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
						g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
					}
				}
			}
		} else if (t==1) {
			for (int i=1;i<=n;i++) {
				u=x-i,v=y;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
				u=x+i,v=y;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
				u=x,v=y-i;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
				u=x,v=y+i;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
			}
		} else {
			for (int i=1;i<=n;i++) {
				u=x-i,v=y-i;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
				u=x+i,v=y-i;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
				u=x+i,v=y+i;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
				u=x-i,v=y+i;
				if (u>=1&&v>=1&&u<=n&&v<=n) {
					if (cur+1==a[u][v]) {
						if (f[u][v][t][cur+1]>f[x][y][t][cur]+1) {
							f[u][v][t][cur+1]=f[x][y][t][cur]+1;
							g[u][v][t][cur+1]=g[x][y][t][cur];
							q.push({u,v,t,cur+1});
						} else if (f[u][v][t][cur+1]==f[x][y][t][cur]+1) {
							g[u][v][t][cur+1]=min(g[u][v][t][cur+1],g[x][y][t][cur]);
						}
					} else {
						if (f[u][v][t][cur]>f[x][y][t][cur]+1) {
							f[u][v][t][cur]=f[x][y][t][cur]+1;
							g[u][v][t][cur]=g[x][y][t][cur];
							q.push({u,v,t,cur});
						} else if (f[u][v][t][cur]==f[x][y][t][cur]+1) {
							g[u][v][t][cur]=min(g[u][v][t][cur],g[x][y][t][cur]);
						}
					}
				}
			}
		}
	}
	u=pos[n*n].first,v=pos[n*n].second;
	int res1=min({f[u][v][0][n*n],f[u][v][1][n*n],f[u][v][2][n*n]}),res2=INT_MAX;
	if (f[u][v][0][n*n]==res1) res2=min(res2,g[u][v][0][n*n]);
	if (f[u][v][1][n*n]==res1) res2=min(res2,g[u][v][1][n*n]);
	if (f[u][v][2][n*n]==res1) res2=min(res2,g[u][v][2][n*n]);
	cout<<res1<<' '<<res2;
}