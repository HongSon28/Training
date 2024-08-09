#include<bits/stdc++.h>
using namespace std;
struct dat{
    int x,y,cnt;
};
int res=INT_MAX;
int r,c;
int end_x,end_y,start_x,start_y;
char a[101][101];
bool vis[101][101];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<dat>q;
bool check(int x,int y) {
    if (x>=1&&y>=1&&x<=r&&y<=c&&vis[x][y]==false&&a[x][y]=='.') return true;
    return false;
}
int main() {
    cin>>r>>c;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin>>a[i][j];
            if (a[i][j]=='B') {
                end_x=i;
                end_y=j;
            } else if (a[i][j]=='C') {
                start_x=i;
                start_y=j;
                vis[i][j]=true;
                q.push({i,j,0});
            }
        }
    }
    while (!q.empty()) {
        dat t=q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if (end_x==x&&end_y==y) res=min(res,t.cnt+1);
            else if (check(x,y)) {
                q.push({x,y,t.cnt+1});
                vis[x][y]=true;
            }
        }
    }
    cout<<res;
}
