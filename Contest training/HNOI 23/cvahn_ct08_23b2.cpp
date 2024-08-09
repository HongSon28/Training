#include<bits/stdc++.h>
using namespace std;
int m,n,cnt=0,mx=0,area=0;
int a[101][101];
bool vis[101][101];
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,-1,1,-1};
void rec(int x,int y,int val){
    area++;
    vis[x][y]=true;
    for (int i=0;i<8;i++) {
        int tx=x+dx[i],ty=y+dy[i];
        if (tx>=1&&ty>=1&&tx<=m&&ty<=n&&vis[tx][ty]==false&&a[tx][ty]==val) {
            rec(tx,ty,val);
        }
    }
}
int main() {
    freopen("BANGSO.INP","r",stdin);
    freopen("BANGSO.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (!vis[i][j]) {
                cnt++;
                area=0;
                rec(i,j,a[i][j]);
                if (area==1) cnt--;
                mx=max(mx,area);
            }
        }
    }
    cout<<cnt<<endl<<mx;
}
