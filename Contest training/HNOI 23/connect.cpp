#include<bits/stdc++.h>
using namespace std;
const int N=500;
int m,n;
int inf=1e9;
int res=inf;
char a[N+5][N+5];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
struct dat{
    int p,x,y;
};
queue<dat>pq[10*(N+N)+5];
struct dat2{
    int x,y,conl,conr;
};
queue<dat2>qq[10*(N+N)+5];
int d[2][N+5][N+5],dis[N+5][N+5][2][2];
bool check(int x,int y) {
    if (x>=1&&y>=1&&x<=m&&y<=n) return true;
    return false;
}
void dij(int s) {
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            d[0][i][j]=d[1][i][j]=inf;
    for (int i=1;i<=m;i++) {
        d[0][i][1]=0;
        d[1][i][n]=0;
        pq[0].push({0,i,1});
        pq[0].push({1,i,n});
    }
    for (int du=0;du<=10*(N+5);du++) {
        while (!pq[du].empty()) {
            int x=pq[du].front().x,y=pq[du].front().y,p=pq[du].front().p;
            pq[du].pop();
            if (du!=d[p][x][y]) continue;
            for (int i=0;i<4;i++) {
                int tx=x+dx[i],ty=y+dy[i];
                if (!check(tx,ty)) continue;
                if (d[p][tx][ty]>du+abs(s-abs(a[x][y]-'0'))) {
                    d[p][tx][ty]=du+abs(s-abs(a[x][y]-'0'));
                    pq[d[p][tx][ty]].push({p,tx,ty});
                }
            }
        }
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            dis[i][j][0][0]=dis[i][j][1][0]=dis[i][j][0][1]=dis[i][j][1][1]=inf;
    for (int j=1;j<=n;j++) {
        dis[1][j][0][0]=abs(s-(int)(a[1][j]-'0'));
        qq[dis[1][j][0][0]].push({1,j,0,0});
    }
    for (int du=0;du<=10*(N+N);du++) {
        while (!qq[du].empty()) {
            int x=qq[du].front().x,y=qq[du].front().y,conl=qq[du].front().conl,conr=qq[du].front().conr;
            qq[du].pop();
            if (du!=dis[x][y][conl][conr]) continue;
            if (conl==0&&dis[x][y][1][conr]>du+d[0][x][y]) {
                dis[x][y][1][conr]=du+d[0][x][y];
                qq[dis[x][y][1][conr]].push({x,y,1,conr});
            }
            if (conr==0&&dis[x][y][conl][1]>du+d[1][x][y]) {
                dis[x][y][conl][1]=du+d[1][x][y];
                qq[dis[x][y][conl][1]].push({x,y,conl,1});
            }
            if (conl==0&&conr==0&&dis[x][y][1][1]>du+d[0][x][y]+d[1][x][y]) {
                dis[x][y][1][1]=du+d[0][x][y]+d[1][x][y];
                qq[dis[x][y][1][1]].push({x,y,1,1});
            }
            for (int i=0;i<4;i++) {
                int tx=x+dx[i],ty=y+dy[i];
                if (!check(tx,ty)) continue;
                if (dis[tx][ty][conl][conr]>du+abs(s-(int)(a[tx][ty]-'0'))) {
                    dis[tx][ty][conl][conr]=du+abs(s-(int)(a[tx][ty]-'0'));
                    qq[dis[tx][ty][conl][conr]].push({tx,ty,conl,conr});
                }
            }
        }
    }
    for (int j=1;j<=n;j++) {
        res=min(res,dis[m][j][1][1]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=0;i<=9;i++) dij(i);
    cout<<res;
}
