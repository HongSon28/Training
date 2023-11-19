#include<bits/stdc++.h>
using namespace std;
const int N=500;
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
int n,m,t;
long long h[N+5][N+5],d[N+5][N+5],s[N+5][N+5],res;
struct Edge{
    pair<int,int>u,v;
    long long w;
    bool operator < (const Edge &other) const {
        return w<other.w;
    }
};
vector<Edge>vc;
bool check(int x,int y) {
    if (x>=1&&y>=1&&x<=n&&y<=m) return true;
    return false;
}
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("SKI.INP","r",stdin);
    //freopen("SKI.OUT","w",stdout);
    memset(par,-1,sizeof(par));
    cin>>n>>m>>t;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>h[i][j];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>s[i][j];
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=0;k<4;k++) {
                int x=i+dx[k],y=j+dy[k];
                if (!check(x,y)) continue;
                vc.push_back({{x,y},{i,j},abs(h[x][y]-h[i][j])});
            }
        }
    }
    sort(vc.begin(),vc.end());
    for (auto e:vc) {
        if (findroot(e.u)==findroot(e.v)) continue;
        pair<int,int> u=findroot(e.u),v=findroot(e.v);
        if (-par[u.first][u.second].first>=t&&-par[v.first][v.second].first>=t) continue;
        if (-par[u.first][u.second].first<t&&-par[v.first][v.second].first<t) {
            Union(u,v);
            d[findroot(u).first][findroot(u).second]=e.w;
        } else {
            if (-par[u.first][u.second].first<t) {
                par[u.first][u.second].first=-t;
                d[u.first][u.second]=e.w;
            }
            else {
                par[v.first][v.second].first=-t;
                d[u.first][u.second]=e.w;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (s[i][j]==0) continue;
            pair<int,int>temp=findroot({i,j});
            res+=d[temp.first][temp.second];
            //cout<<i<<' '<<j<<' '<<temp.first<<' '<<temp.second<<' '<<-par[temp.first][temp.second].first<<' '<<d[temp.first][temp.second]<<endl;
        }
    }
    cout<<res;
}
/*
5 5 2
2 5 3 4 1
3 2 6 3 2
1 1 5 3 5
4 3 7 2 4
5 3 2 5 1
1 0 0 1 1
0 0 1 1 0
0 0 0 0 0
1 0 0 0 1
0 0 0 1 0
*/
