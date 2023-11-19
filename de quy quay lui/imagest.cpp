#include<bits/stdc++.h>
using namespace std;
int n;
int cur;
char c[31][31];
bool vis[31][31];
int dx[]={1,1,1,-1,-1,-1,0,0};
int dy[]={1,0,-1,1,0,-1,1,-1};
void dfs(int x,int y) {
    vis[x][y]=true;
    for (int i=0;i<8;i++) {
        int u=x+dx[i],v=y+dy[i];
        if (!vis[u][v]&&u>=1&&v>=1&&u<=n&&v<=n&&c[u][v]=='1') dfs(u,v);
    }
}
int main() {
    while (cin>>n) {
        cur++;
        int cnt=0;
        if (n==0) break;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cin>>c[i][j];
                vis[i][j]=false;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if(c[i][j]=='1'&&!vis[i][j]) {
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cur<<' '<<cnt<<endl;
    }
}
