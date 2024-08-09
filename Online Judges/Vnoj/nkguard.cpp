#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,res;
int a[N][N];
bool vis[N][N];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,-1,1,-1,0,1};
bool check(int x,int y) {
    for (int i=0;i<8;i++) {
        if (a[x][y]<a[x+dx[i]][y+dy[i]]) return false;
    }
    return true;
}
void bfs(int x, int y) {
    queue<pair<int,int>>q;
    q.push({x,y});
    while (!q.empty()) {
        pair<int,int>t=q.front();
        q.pop();
        for (int i=0;i<8;i++) {
            int tx=t.first+dx[i],ty=t.second+dy[i];
            if (tx>=1&&tx<=n&&ty>=1&&ty<=m&&vis[tx][ty]==false&&a[tx][ty]<=a[t.first][t.second]) {
                //cout<<tx<<' '<<ty<<endl;
                vis[tx][ty]=true;
                q.push({tx,ty});
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            vis[i][j]=false;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
           if (vis[i][j]==false&&check(i,j)==true) {
                vis[i][j]=true;
                res++;
                //cout<<i<<' '<<j<<' '<<res<<endl;
                bfs(i,j);
            }
        }
    }
    cout<<res;
}
