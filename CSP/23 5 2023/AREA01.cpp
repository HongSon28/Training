#include<bits/stdc++.h>
using namespace std;
int m,n,res,cnt;
const int N=1e3;
char c[N+5][N+5];
bool vis[N+5][N+5];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
void dfs(int i,int j) {
    for (int k=0;k<4;k++) {
        int x=i+dx[k],y=j+dy[k];
        if (!vis[x][y]&&c[x][y]==c[i][j]) {
            //cout<<x<<' '<<y<<endl;
            cnt++;
            vis[x][y]=true;
            dfs(x,y);
        }
    }
}
int main() {
    freopen("AREA01.INP","r",stdin);
    freopen("AREA01.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            cin>>c[i][j];
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (!vis[i][j]) {
                cnt=0;
                dfs(i,j);
                res=max(res,cnt);
            }
        }
    }
    cout<<res;
}
