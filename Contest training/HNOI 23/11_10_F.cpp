#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=1e4;
pair<int,int> par[N+5][N+5];
pair<int,int> findroot(pair<int,int>x) {
    if (par[x.first][x.second].first<0) return x;
    return par[x.first][x.second]=findroot(par[x.first][x.second]);
}
void Union(pair<int,int>x,pair<int,int>y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y.first][y.second]<par[x.first][x.second]) swap(x,y);
    par[x.first][x.second].first+=par[y.first][y.second].first;
    par[y.first][y.second]=x;
}
int m,n,q;
int a[N+5][N+5];
struct query{
    int x,y,u,v;
} qu[M+5];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int res[M+5],cur;
bool check(int x,int y) {
    if (x>=1&&y>=1&&x<=m&&y<=n) return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>m>>n>>q;
    cur=m*n;
    for (int i=1;i<=q;i++) {
        cin>>qu[i].x>>qu[i].y>>qu[i].u>>qu[i].v;
        for (int x=qu[i].x;x<=qu[i].u;x++)
            for (int y=qu[i].y;y<=qu[i].v;y++)
                a[x][y]++;
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]!=0) {
                cur--;
                continue;
            }
            for (int k=0;k<4;k++) {
                int x=i+dx[k],y=j+dy[k];
                if (!check(x,y)) continue;
                if (a[x][y]!=0) continue;
                if (findroot({i,j})==findroot({x,y})) continue;
                Union({i,j},{x,y});
                cur--;
            }
        }
    }
    res[q]=cur;
    for (int i=q-1;i>=1;i--) {
        for (int x=qu[i+1].x;x<=qu[i+1].u;x++) {
            for (int y=qu[i+1].y;y<=qu[i+1].v;y++) {
                a[x][y]--;
                if (a[x][y]==0) cur++;
            }
        }
        for (int x=qu[i+1].x;x<=qu[i+1].u;x++) {
            for (int y=qu[i+1].y;y<=qu[i+1].v;y++) {
                if (a[x][y]!=0) continue;
                for (int k=0;k<4;k++) {
                    int xx=x+dx[k],yy=y+dy[k];
                    if (!check(xx,yy)) continue;
                    if (a[xx][yy]!=0) continue;
                    if (findroot({xx,yy})!=findroot({x,y})) {
                        Union({xx,yy},{x,y});
                        cur--;
                    }
                }
            }
        }
        res[i]=cur;
    }
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}
