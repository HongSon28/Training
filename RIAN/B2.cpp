#include<bits/stdc++.h>
using namespace std;
struct td {
    int x,y,cnt;
};
bool vis[12][12];
struct tv {
    int x,y;
};
int xg, yg, xd, yd;
char a[12][12];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
tv par[12][12];
bool check (int x,int y) {
    if (x>=1&&y>=1&&x<=11&&y<=11) return true;
    return false;
}
int bfs() {
    queue<td> q;
    q.push({xg,yg,0});
    while (q.empty()==false) {
        td t=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if (a[x][y]=='C') {
                xd=t.x;
                yd=t.y;
                return t.cnt;
            }
        }
        for (int i=0;i<4;i++) {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if (check(x,y)==true&&vis[x][y]==false&&a[x][y]=='.') {
                vis[x][y]=true;
                par[x][y]={t.x,t.y};
                q.push({x,y,t.cnt+1});
            }
        }
    }
    return -1;
}
int main() {
    freopen("PFIND.INP", "r", stdin);
    freopen("PFIND.OUT", "w", stdout);
    for (int i=1;i<=11;i++) {
        for (int j=1;j<=11;j++) {
            cin>>a[i][j];
            if (a[i][j]=='R') {
                xg=i;
                yg=j;
            }
        }
    }
    for (int i=0;i<=11;i++) {
        for (int j=0;j<=11;j++) {
            par[i][j]= {0,0};
            vis[i][j]=false;
        }
    }
    vis[xg][yg]=true;
    int res=bfs();
    if (res==-1) {
        cout<<"Khong co duong";
    } else if (res==0) {
        cout<<0;
    } else {
        cout<<res<<endl;
        vector<tv>path;
        int tx=par[xd][yd].x,ty=par[xd][yd].y;
        while (true) {
            path.push_back({tx,ty});
            int x=tx;
            int y=ty;
            tx=par[x][y].x;
            ty=par[x][y].y;
            if (tx==0&&ty==0) break;
        }
        reverse(path.begin(),path.end());
        for (int i=1;i<path.size();i++) {
            cout<<path[i].x<<' '<<path[i].y<<endl;
        }
        cout<<xd<<' '<<yd;
    }
}
