#include<bits/stdc++.h>
using namespace std;
struct td {
    int x,y,cnt;
};
bool visit[101][101];
int n;
int sx,sy,x2,y2;
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
bool check(int x, int y) {
    if (x>=1&&x<=n&&y>=1&&y<=n) return true;
    return false;
}
int bfs() {
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        visit[i][j]=false;
    visit[sx][sy]=true;
    queue<td>q;
    q.push({sx,sy,0});
    while (q.empty()==false) {
        td t=q.front();
        q.pop();
        if (t.x==x2&&t.y==y2)
            return t.cnt;
        for (int i=0;i<8;i++) {
            int x=t.x+dx[i];
            int y=t.y+dy[i];
            if (check(x,y)==true&&visit[x][y]==false) {
                visit[x][y]==true;
                q.push({x,y,t.cnt+1});
            }
        }
    }
}
int main() {
    cin>>n;
    cin>>sx>>sy>>x2>>y2;
    cout<<bfs();
}
