#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int m,n,res;
char c[N+5][N+5];
queue<pair<int,int>>q;
bool vis[N+5][N+5];
pair<int,int>direct[N+5][N+5][4];
bool check(int i,int j) {
    if (vis[i][j]) return false;
    char temp=c[i][j];
    if (temp=='W') return !direct[i][j][0].first;
    if (temp=='E') return !direct[i][j][2].first;
    if (temp=='N') return !direct[i][j][1].first;
    if (temp=='S') return !direct[i][j][3].first;
    return false;
}
void init() {
    memset(vis,false,sizeof(vis));
    res=0;
    memset(direct,0,sizeof(direct));
    for (int i=1;i<=m;i++) {
        pair<int,int> last={0,0};
        for (int j=1;j<=n;j++) {
            if (c[i][j]=='.') continue;
            direct[i][j][0]=last;
            last={i,j};
        }
        last={0,0};
        for (int j=n;j>=1;j--) {
            if (c[i][j]=='.') continue;
            direct[i][j][2]=last;
            last={i,j};
        }
    }
    for (int j=1;j<=n;j++) {
        pair<int,int> last={0,0};
        for (int i=1;i<=m;i++) {
            if (c[i][j]=='.') continue;
            direct[i][j][1]=last;
            last={i,j};
        }
        last={0,0};
        for (int i=m;i>=1;i--) {
            if (c[i][j]=='.') continue;
            direct[i][j][3]=last;
            last={i,j};
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CARDRAG.INP","r",stdin);
    freopen("CARDRAG.OUT","w",stdout);
    while(cin>>m>>n) {
        if (m==n&&n==0) return 0;
        for (int i=1;i<=m;i++)
            for (int j=1;j<=n;j++)
                cin>>c[i][j];
        init();
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++) {
                if (check(i,j)) {
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        while (!q.empty()) {
            pair<int,int>temp=q.front();
            q.pop();
            res++;
            pair<int,int>prev=direct[temp.first][temp.second][0],next=direct[temp.first][temp.second][2];
            direct[prev.first][prev.second][2]=next,direct[next.first][next.second][0]=prev;
            if (prev.first&&check(prev.first,prev.second)) {
                vis[prev.first][prev.second]=true;
                q.push(prev);
            }
            if (next.first&&check(next.first,next.second)) {
                vis[next.first][next.second]=true;
                q.push(next);
            }
            prev=direct[temp.first][temp.second][1],next=direct[temp.first][temp.second][3];
            direct[prev.first][prev.second][3]=next,direct[next.first][next.second][1]=prev;
            if (prev.first&&check(prev.first,prev.second)) {
                vis[prev.first][prev.second]=true;
                q.push(prev);
            }
            if (next.first&&check(next.first,next.second)) {
                vis[next.first][next.second]=true;
                q.push(next);
            }
        }
        cout<<res<<'\n';
    }
}
