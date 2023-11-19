#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int m,n;
int res=INT_MAX;
int a[N+5][N+5];
int mx[N+5][N+5];
bool vis[N+5][N+5];
int dx[]={0,0,1};
int dy[]={1,-1,0};
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            mx[i][j]=INT_MAX;
        }
    }
    for (int i=1;i<=m;i++) mx[i][1]=1;
    queue<pair<int,int>>q;
    for(int i=1;i<=m;i++) {
        q.push({i,1});
        vis[i][1]=true;
    }
    while (!q.empty()) {
        pair<int,int>p=q.front();
        q.pop();
        for (int i=0;i<3;i++) {
            int x=p.first+dx[i];
            int y=p.second+dy[i];
            if (x>m||y>n||x<1||y<1) continue;
            if (!vis[x][y]) {
                q.push({x,y});
                vis[x][y]=true;
                if (a[x][y]==a[p.first][p.second]) mx[x][y]=min(mx[x][y],mx[p.first][p.second]);
                else mx[x][y]=min(mx[x][y],mx[p.first][p.second]+1);
            } else {
                if (a[x][y]==a[p.first][p.second]) mx[x][y]=min(mx[x][y],mx[p.first][p.second]);
                else mx[x][y]=min(mx[x][y],mx[p.first][p.second]+1);
            }
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cout<<mx[i][j]<< ' ';
        }
        cout<<endl;
    }
    for (int i=1;i<=m;i++) res=min(res,mx[i][n]);
    cout<<res;
}
