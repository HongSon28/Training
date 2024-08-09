#include<bits/stdc++.h>
using namespace std;
const int N=250;
int m,n;
int co,cv;
int wolf,sheep;
char c[N+5][N+5];
bool vis[N+5][N+5];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void dfs(int i,int j) {
    for (int k=0;k<4;k++) {
        int x=i+dx[k],y=j+dy[k];
        if (x>=1&&y>=1&&x<=m&&y<=n&&c[x][y]!='#'&&!vis[x][y]) {
            if (c[x][y]=='o') co++;
            if (c[x][y]=='v') cv++;
            vis[x][y]=true;
            dfs(x,y);
        }
    }
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>c[i][j];
            if (c[i][j]=='o') sheep++;
            else if (c[i][j]=='v') wolf++;
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if(!vis[i][j]&&c[i][j]!='#') {
                co=0,cv=0;
                vis[i][j]=true;
                if (c[i][j]=='o') co++;
                else if (c[i][j]=='v') cv++;
                dfs(i,j);
                if (co>cv) wolf-=cv;
                else sheep-=co;
            }
        }
    }
    cout<<sheep<<' '<<wolf;
}
