#include<bits/stdc++.h>
using namespace std;
const int N=200;
int m,n;
int a[N+5][N+5],d[N+5][N+5],inf=1e9,res=inf;
int dx[]={0,-1,1,0};
int dy[]={1,0,0,-1};
struct dat {
    int u,v,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("HC.INP","r",stdin);
    freopen("HC.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            d[i][j]=inf;
        }
    }
    for (int i=1;i<=m;i++) {
        d[i][1]=a[i][1];
        pq.push({i,1,d[i][1]});
    }
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int u=t.u,v=t.v,du=t.d;
        if (du!=d[u][v]) continue;
        for (int i=0;i<4;i++) {
            int x=u+dx[i],y=v+dy[i];
            if (x>=1&&y>=1&&x<=m&&y<=n&&d[x][y]>du+a[x][y]) {
                d[x][y]=du+a[x][y];
                pq.push({x,y,d[x][y]});
            }
        }
    }
    for (int i=1;i<=m;i++) res=min(res,d[i][n]);
    cout<<res;
}
