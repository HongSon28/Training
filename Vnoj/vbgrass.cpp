#include<bits/stdc++.h>
using namespace std;
int r,c;
const int N=1e2;
int res;
char ch[N+5][N+5];
bool vis[N+5][N+5];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void dfs(int i,int j) {
    for (int k=0;k<4;k++) {
        int x=i+dx[k],y=j+dy[k];
        if (!vis[x][y]&&ch[x][y]=='#') {
            vis[x][y]=true;
            dfs(x,y);
        }
    }
}
int main() {
    cin>>r>>c;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
            cin>>ch[i][j];
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (!vis[i][j]&&ch[i][j]=='#') {
                //cout<<i<<' '<<j<<endl;
                res++;
                vis[i][j]=true;
                dfs(i,j);
            }
        }
    }
    cout<<res;
}
