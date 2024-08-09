#include<bits/stdc++.h>
using namespace std;
const int N=100;
int m,n;
int a[N+5][N+5],d[N+5][N+5][N+5],inf=1e9;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int x_1,y_1,x_2,y_2;
struct dat{
    int u,v,h,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    cin>>x_1>>y_1>>x_2>>y_2;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=0;k<=a[i][j]+1;k++) {
                d[i][j][k]=inf;
            }
        }
    }
    d[x_1][y_1][0]=0;
    pq.push({x_1,y_1,0,0});
    while (!pq.empty()) {
        dat temp=pq.front();
        pq.pop();
        int u=temp.u,v=temp.v,du=temp.d,h=temp.h;
        if (d[u][v][h]!=du) continue;
        for (int i=0;i<4;i++) { //1
            int x=u+dx[i],y=v+dy[i];
            if (x>=1&&y>=1&&x<=m&&y<=n&&h==a[u][v]+1&&a[x][y]==a[u][v]&&d[x][y][h]>du+1) {
                d[x][y][h]=du+1;
                pq.push({x,y,h,d[x][y][h]});
            }
        }
        if (h==a[u][v]&&d[u][v][h+1]>du+1) { //4
            d[u][v][h+1]=du+1;
            pq.push({u,v,h+1,d[u][v][h+1]});
        }

    }
}
