#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
int n,m;
struct Edge{
    long long u,v,w,id;
    bool operator < (const Edge &others) const {
        return w<others.w;
    }
};
Edge edge[N+5];
vector<vector<pair<long long, long long>>>adj(N+5);
long long par[N+5];
long long sum;
long long res[N+5];
bool used[N+5];
long long findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
long long up[N+5][LG+5],h[N+5],mx[N+5][LG+5];
void dfs(int u) {
    for (auto t:adj[u]) {
        long long v=t.first,w=t.second;
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        mx[v][0]=w;
        for (int j=1;j<=LG;j++) {
            up[v][j]=up[up[v][j-1]][j-1];
            mx[v][j]=max(mx[v][j-1],mx[up[v][j-1]][j-1]);
        }
        dfs(v);
    }
}
long long lca(int u,int v) {
    long long g=0;
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        long long k=h[u]-h[v];
        for (int j=0;(1<<j)<=k;j++) {
            if ((k>>j)&1) {
                g=max(g,mx[u][j]);
                u=up[u][j];
            }
        }
    }
    if (u==v) return g;
    long long k=__lg(h[u]);
    for (int j=k;j>=0;j--) {
        if (up[u][j]!=up[v][j]){
            g=max(g,mx[u][j]);
            g=max(g,mx[v][j]);
            u=up[u][j];
            v=up[v][j];
        }
    }
    g=max(g,mx[u][0]);
    g=max(g,mx[v][0]);
    return g;
}
int main() {
    freopen("EMST.INP","r",stdin);
    freopen("EMST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        edge[i].id=i;
    }
    sort(edge+1,edge+1+m);
    for (int i=1;i<=m;i++) {
        if (findroot(edge[i].u)!=findroot(edge[i].v)) {
            Union(edge[i].u,edge[i].v);
            adj[edge[i].u].push_back({edge[i].v,edge[i].w});
            adj[edge[i].v].push_back({edge[i].u,edge[i].w});
            used[i]=true;
            sum+=edge[i].w;
        }
    }
    dfs(1);
    for (int i=1;i<=m;i++) {
        if (used[i]) res[edge[i].id]=sum;
        else {
            long long temp=lca(edge[i].u,edge[i].v);
            res[edge[i].id]=sum-temp+edge[i].w;
        }
    }
    for (int i=1;i<=m;i++) cout<<res[i]<<'\n';
}
