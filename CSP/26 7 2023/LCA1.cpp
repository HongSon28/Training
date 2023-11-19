#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int n,m;
vector<vector<int>>adj(N+5);
int up[N+5][LG+5],h[N+5];
void dfs(int u) {
    for (auto v:adj[u]) {
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        for (int j=1;j<=LG;j++) {
            up[v][j]=up[up[v][j-1]][j-1];
        }
        dfs(v);
    }
}
int lca(int u,int v) {
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        int k=h[u]-h[v];
        for (int j=0;(1<<j)<=k;j++) {
            if ((k>>j)&1)
                u=up[u][j];
        }
    }
    if (u==v) return u;
    int k=__lg(h[u]);
    for (int j=k;j>=0;j--) {
        if (up[u][j]!=up[v][j]){
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}
int main() {
    freopen("LCA1.INP","r",stdin);
    freopen("LCA1.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    while (m--) {
        int u,v;
        cin>>u>>v;
        int k=lca(u,v);
        cout<<h[u]-h[k]+h[v]-h[k]<<endl;
    }
}
