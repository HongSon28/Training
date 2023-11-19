#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
bool p[N+5];
int m,n,cnt;
int a[100][100];
bool vis[100][100];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void dfs(int x,int y) {
    vis[x][y]=true;
    for (int i=0;i<4;i++) {
        int tx=x+dx[i],ty=y+dy[i];
        if (!vis[tx][ty]&&p[a[tx][ty]]&&tx>=1&&ty>=1&&tx<=m&&ty<=n) {
            dfs(tx,ty);
        }
    }
}
void sang() {
    memset(p,true,sizeof(p));
    p[0]=false,p[1]=false;
    for (int i=2;i<=N;i++) {
        if(p[i]) {
            for (int j=i*2;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    sang();
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (!vis[i][j]&&p[a[i][j]]) {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout<<cnt;
}
