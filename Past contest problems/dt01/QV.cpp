#include<bits/stdc++.h>
using namespace std;
const int N=100;
int m,n;
int a[N+5][N+5];
bool vis[N+5][N+5];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int cnt,mx;
int area,id;
void dfs(int i,int j) {
    vis[i][j]=true;
    for (int k=0;k<4;k++) {
        int x=i+dx[k],y=j+dy[k];
        if (x>=0&&y>=0&&x<=m+1&&y<=n+1&&a[i][j]>a[x][y]) area+=a[i][j]-a[x][y];
        if (x>=1&&y>=1&&x<=m&&y<=n&&!vis[x][y]&&a[x][y]!=0) dfs(x,y);
    }
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (!vis[i][j]&&a[i][j]!=0) {
                area=0;
                cnt++;
                dfs(i,j);
                if (area>mx) {
                    mx=area;
                    id=cnt;
                }
            }
        }
    }
    cout<<cnt<<endl<<id<<' '<<mx;
}
/* 4 6
1 2 3 0 2 1
1 0 1 0 0 1
2 1 1 0 0 1
0 0 0 1 1 0
*/
