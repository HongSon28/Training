#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int m,n;
int a[N+5][N+5];
int mn[N+5][N+5];
bool vis[N+5][N+5];
queue<pair<int,int>>q1,q2;
int dx[]={0,-1,1};
int dy[]={1,0,0};
int main() {
    freopen("FAIR.INP","r",stdin);
    freopen("FAIR.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            mn[i][j]=INT_MAX;
        }
    }
    for (int i=1;i<=m;i++) {
        mn[i][1]=1;
        q1.push({i,1});
    }
    while (!q1.empty()||!q2.empty()) {
        while (!q1.empty()) {
            pair<int,int> p=q1.front();
            q1.pop();
            if (p.second==n) {
                cout<<mn[p.first][p.second];
                return 0;
            }
            for (int i=0;i<3;i++) {
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if (x>=1&&y>=1&&x<=m&&y<=n&&mn[p.first][p.second]+(a[p.first][p.second]!=a[x][y])<mn[x][y]){
                    mn[x][y]=mn[p.first][p.second]+(a[p.first][p.second]!=a[x][y]);
                    //cout<<p.first<<' '<<p.second<<' '<<mn[p.first][p.second]<<' '<<x<<' '<<y<<' '<<mn[x][y]<<endl;
                    if (a[p.first][p.second]==a[x][y]) q1.push({x,y});
                    else q2.push({x,y});
                }
            }
        }
        swap(q1,q2);
    }
}
