#include<bits/stdc++.h>
using namespace std;
const int N=4e4;
int par[N+5];
int find_root(int u) {
    if (par[u]<0) return u;
    return par[u]=find_root(par[u]);
}
void Union(int u,int v) {
    if ((u=find_root(u))==(v=find_root(v))) return;
    if (par[v]>par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int n,m;
vector<pair<int,int>>v;
struct edge{
    int u,v,w;
    bool operator < (const edge &other) const {
        return w<other.w;
    }
} e[N+5];
int res,cnt;
int main() {
   // freopen("CITY.INP","r",stdin);
   // freopen("CITY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+1+m);
    for (int i=1;i<=m;i++) {
        if (find_root(e[i].u)==find_root(e[i].v)) continue;
        cnt++;
        res+=e[i].w;
        Union(e[i].u,e[i].v);
        v.push_back({e[i].u,e[i].v});
    }
    sort(v.begin(),v.end());
    cout<<cnt<<' '<<res<<'\n';
    for (auto p:v) cout<<p.first<<' '<<p.second<<'\n';
}
