#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
struct dir{
    bool East,West,North,South;
};
struct dat{
    int x,y,cnt;
};
dir a[N+5][N+5];
bool vis[N+5][N+5];
string s;
int n;
int x=1000,y=1000;
void bfs() {
    queue<dat>q;
    q.push({x,y,0});
    vis[x][y]=true;
    while (!q.empty()) {
        dat t=q.front();
        q.pop();
        if (t.x==1000&&t.y==1000) {
            cout<<t.cnt;
            return;
        }
        if (a[t.x][t.y].East) {
            int tx=t.x,ty=t.y+1;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[tx][ty]) {
                vis[tx][ty]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
        if (a[t.x][t.y].West) {
            int tx=t.x,ty=t.y-1;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[tx][ty]) {
                vis[tx][ty]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
        if (a[t.x][t.y].North) {
            int tx=t.x-1,ty=t.y;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[tx][ty]) {
                vis[tx][ty]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
        if (a[t.x][t.y].South) {
            int tx=t.x+1,ty=t.y;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[tx][ty]) {
                vis[tx][ty]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
    }
}
int main() {
    //freopen("TIMDUONG.INP","r",stdin);
    //freopen("TIMDUONG.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for (auto i:s) {
        if (i=='D') {
            a[x][y].East=true;
            a[x][y+1].West=true;
            y++;
        } else if (i=='T') {
            a[x][y].West=true;
            a[x][y-1].East=true;
            y--;
        } else if (i=='N') {
            a[x][y].South=true;
            a[x+1][y].North=true;
            x++;
        } else {
            a[x][y].North=true;
            a[x-1][y].South=true;
            x--;
        }
    }
    bfs();
}
