#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int x_1,y_1,x_2,y_2;
long long a[N+5][N+5];
long long lo=0,hi=2e9,res;
queue<pair<int,int>>q;
bool vis[N+1][N+1];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
bool check(long long diff) {
    memset(vis,false,sizeof(vis));
    while (!q.empty()) q.pop();
    q.push({x_1,y_1});
    vis[x_1][y_1]=true;
    while (!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int tx=x+dx[i],ty=y+dy[i];
            if (tx>=1&&ty>=1&&tx<=m&&ty<=n&&!vis[tx][ty]&&abs(a[tx][ty]-a[x][y])<=diff) {
                vis[tx][ty]=true;
                q.push({tx,ty});
            }
        }
    }
    if (vis[x_2][y_2]) return true;
    return false;
}
int main() {
    freopen("BAI3.INP","r",stdin);
    freopen("BAI3.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    cin>>x_1>>y_1>>x_2>>y_2;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}
/*
3 4
1 1 3 3
-2 9 3 4
0 3 7 -4
8 -9 9 10
*/

