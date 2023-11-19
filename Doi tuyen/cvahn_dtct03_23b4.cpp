#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
int x_1,x_2,x_3,y_1,y_2,y_3;
long long a[N+5][N+5];
long long inf=1e18;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct dat{
    long long x,y,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
int dij(int sx,int sy,int tx,int ty) {
    priority_queue<dat>pq;
    long long d[n+1][m+1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            d[i][j]=inf;
    d[sx][sy]=0;
    pq.push({sx,sy,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int x=t.x,y=t.y,td=t.d;
        if (td!=d[x][y]) continue;
        for (int i=0;i<4;i++) {
            int nx=x+dx[i],ny=y+dy[i];
            if (nx>=1&&ny>=1&&nx<=n&&ny<=m)
                if (td+a[nx][ny]<d[nx][ny]) {
                    d[nx][ny]=td+a[nx][ny];
                    pq.push({nx,ny,d[nx][ny]});
                }
        }
    }
    return d[tx][ty];
}
int main() {
    cin>>n>>m;
    cin>>x_1>>y_1>>x_2>>y_2>>x_3>>y_3;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    long long c1=dij(1,1,x_1,y_1)+dij(x_1,y_1,x_2,y_2)+dij(x_2,y_2,n,m);
    long long c2=dij(1,1,x_2,y_2)+dij(x_2,y_2,x_1,y_1)+dij(x_1,y_1,n,m);
    long long c3=dij(1,1,x_1,y_1)+dij(x_1,y_1,x_3,y_3)+dij(x_3,y_3,n,m);
    long long c4=dij(1,1,x_3,y_3)+dij(x_3,y_3,x_1,y_1)+dij(x_1,y_1,n,m);
    long long c5=dij(1,1,x_2,y_2)+dij(x_2,y_2,x_3,y_3)+dij(x_3,y_3,n,m);
    long long c6=dij(1,1,x_3,y_3)+dij(x_3,y_3,x_2,y_2)+dij(x_2,y_2,n,m);
    cout<<min({c1,c2,c3,c4,c5,c6})+a[1][1];
}
