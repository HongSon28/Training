#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m;
int a[N+5][N+5];
bool vis[N+5][N+5];
int sum;
int res;
void calc(int i,int j) {
    if (i==n&&j==m) {
        res=max(res,sum);
        return;
    }
    int x=i,y=j+1;
    if (x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y]) {
        vis[x][y]=true;
        sum+=a[x][y];
        calc(x,y);
        sum-=a[x][y];
        vis[x][y]=false;
    }
    x=i+1,y=j;
    if (x>=1&&y>=1&&x<=n&&y<=m&&!vis[x][y]) {
        vis[x][y]=true;
        sum+=a[x][y];
        calc(x,y);
        sum-=a[x][y];
        vis[x][y]=false;
    }
}
void dfs(int i,int j) {
    if (i==n&&j==m) {
        vis[i][j]=false;
        calc(1,1);
        return;
    }
    int x=i,y=j+1;
    if (x>=1&&y>=1&&x<=n&&y<=m) {
        vis[x][y]=true;
        sum+=a[x][y];
        dfs(x,y);
        sum-=a[x][y];
        vis[x][y]=false;
    }
    x=i+1,y=j;
    if (x>=1&&y>=1&&x<=n&&y<=m) {
        vis[x][y]=true;
        sum+=a[x][y];
        dfs(x,y);
        sum-=a[x][y];
        vis[x][y]=false;
    }
}
int main() {
    freopen("TWOPATHS.INP","r",stdin);
    freopen("TWOPATHS.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    dfs(1,1);
    cout<<res;
}
