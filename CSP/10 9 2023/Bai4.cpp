#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
struct dir{
    bool East,West,North,South;
};
struct dat{
    int x,y,cnt;
};
vector<bool>East(N*N+5),South(N*N+5),North(N*N+5),West(N*N+5);
vector<bool>vis(N*N+5);
string s;
int n;
int x=10000,y=10000;
int conv(int x,int y) {
    return (x-1)*N+y;
}
void bfs() {
    queue<dat>q;
    q.push({x,y,0});
    vis[conv(x,y)]=true;
    while (!q.empty()) {
        dat t=q.front();
        q.pop();
        if (t.x==10000&&t.y==10000) {
            cout<<t.cnt;
            return;
        }
        if (East[conv(t.x,t.y)]) {
            int tx=t.x,ty=t.y+1;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[conv(tx,ty)]) {
                vis[conv(tx,ty)]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
        if (West[conv(t.x,t.y)]) {
            int tx=t.x,ty=t.y-1;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[conv(tx,ty)]) {
                vis[conv(tx,ty)]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
        if (North[conv(t.x,t.y)]) {
            int tx=t.x-1,ty=t.y;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[conv(tx,ty)]) {
                vis[conv(tx,ty)]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
        if (South[conv(t.x,t.y)]) {
            int tx=t.x+1,ty=t.y;
            if (tx>=0&&ty>=0&&tx<=N&&ty<=N&&!vis[conv(tx,ty)]) {
                vis[conv(tx,ty)]=true;
                q.push({tx,ty,t.cnt+1});
            }
        }
    }
}
int main() {
    freopen("BAI4.INP","r",stdin);
    freopen("BAI4.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for (auto i:s) {
        if (i=='D') {
            East[conv(x,y)]=true;
            West[conv(x,y+1)]=true;
            y++;
        } else if (i=='T') {
            West[conv(x,y)]=true;
            East[conv(x,y-1)]=true;
            y--;
        } else if (i=='N') {
            South[conv(x,y)]=true;
            North[conv(x+1,y)]=true;
            x++;
        } else {
            North[conv(x,y)]=true;
            South[conv(x-1,y)]=true;
            x--;
        }
    }
    bfs();
}
