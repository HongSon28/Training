#include<bits/stdc++.h>
using namespace std;
struct td{
    int x,y,cnt;
};
td s;
int m,n;
int res=100000;
int a[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool check(int x, int y) {
    if (x>=1&&x<=m&&y>=1&&y<=n) return true;
    return false;
}
int bfs() {
    queue<td>q;
    q.push(s);
    a[s.x][s.y]=2;
    while (q.empty()==false) {
        td t=q.front();
        q.pop();
        if (t.x==1||t.x==m||t.y==1||t.y==n) {
            res=min(res,t.cnt);
        }
        for (int i=0;i<4;i++) {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if (a[x][y]==0&&check(x,y)==true) {
                a[x][y]=2;
                q.push({x,y,t.cnt+1});
            }
        }
    }
    if (res==100000)return 0;
    return res;
}
int main() {
    cin>>m>>n;
    cin>>s.x>>s.y;
    s.cnt=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    cout<<bfs();
}
