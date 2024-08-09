#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
long long f[N+5],res;
int n;
struct edge{
    long long v,c1,c2;
};
vector<edge>adj[N+5];
int h[N+5];
int up[N+5][LG+5];
void dfs(int u) {
    for (auto e:adj[u]) {
        int v=e.v;
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        for (int i=1;i<=LG;i++) up[v][i]=up[up[v][i-1]][i-1];
        dfs(v);
    }
}
int lca(int u,int v) {
    if (h[u]<h[v]) swap(u,v);
    if (h[u]!=h[v]) {
        int k=h[u]-h[v];
        for (int i=0;(1<<i)<=k;i++) {
            if (k>>i&1) u=up[u][i];
        }
    }
    if (u==v) return u;
    for (int i=LG;i>=0;i--) {
        if (up[u][i]!=up[v][i]) {
            u=up[u][i];
            v=up[v][i];
        }
    }
    return up[u][0];
}
void dfs2(int u) {
    for (auto e:adj[u]) {
        int v=e.v;
        if (v==up[u][0]) continue;
        long long c1=e.c1,c2=e.c2;
        dfs2(v);
        f[u]+=f[v];
        res+=min(f[v]*c1,c2);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
        long long u,v,c1,c2;
        cin>>u>>v>>c1>>c2;
        adj[u].push_back({v,c1,c2});
        adj[v].push_back({u,c1,c2});
    }
    h[1]=1;
    dfs(1);
    for (int i=1;i<n;i++) {
        f[i]++;
        f[i+1]++;
        f[lca(i,i+1)]-=2;
    }
    dfs2(1);
    cout<<res;
}
