#include<bits/stdc++.h>
using namespace std;
int m,n,u,v,rx,ry;
int res=INT_MAX;
bool vis[20][20];
int a[20][20];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
vector<pair<int,int>>path;
pair<int,int>trace[20][20];
struct dat{
    int x,y,cnt;
};
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    cin>>u>>v;
    queue<dat>q;
    q.push({u,v,0});
    vis[u][v]=true;
    while (!q.empty()) {
        dat t=q.front();
        q.pop();
        if (t.x==1||t.y==1||t.x==m||t.y==n) {
            rx=t.x;
            ry=t.y;
            res=t.cnt;
            break;
        }
        for (int i=0;i<4;i++) {
            int x=t.x+dx[i],y=t.y+dy[i];
            if (x>=1&&y>=1&&x<=m&&y<=n&&!vis[x][y]&&a[x][y]==0) {
                q.push({x,y,t.cnt+1});
                vis[x][y]=true;
                trace[x][y]={t.x,t.y};
            }
        }
    }
    if (res==INT_MAX) {
        cout<<-1;
        return 0;
    }
    cout<<res<<endl;
    path.push_back({rx,ry});
    for (int i=1;i<=res;i++) {
        int t1=trace[rx][ry].first,t2=trace[rx][ry].second;
        rx=t1,ry=t2;
        path.push_back({rx,ry});
    }
    for (int i=path.size()-2;i>=0;i--)
        cout<<path[i].first<<' '<<path[i].second<<endl;
}
