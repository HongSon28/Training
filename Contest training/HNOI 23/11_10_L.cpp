#include<bits/stdc++.h>
using namespace std;
const int N=3e5,LG=__lg(N);
int n,m;
vector<vector<int>>adj(N+5);
vector<vector<pair<int,int>>>adj2(N+5);
int a[N+5],b[N+5];
int up[N+5][LG+5],h[N+5],hmin[N+5];
int col[N+5],res;
long long ans=1,mod=1e9+7;
void dfs(int u) {
    for (auto v:adj[u]) {
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        hmin[v]=h[v];
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
void dfs2(int u,int par) {
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs2(v,u);
        hmin[u]=min(hmin[u],hmin[v]);
    }
}
void dfs3(int u) {
    for (auto v:adj2[u]) {
        int next=(col[u]^v.second);
        if (col[v.first]==-1) {
            col[v.first]=next;
            dfs3(v.first);
        } else {
            if (col[v.first]!=next) {
                cout<<0;
                exit(0);
            }
        }
    }
}
int main() {
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
    for (int i=1;i<=m;i++) {
        cin>>a[i]>>b[i];
        int t=lca(a[i],b[i]);
        hmin[a[i]]=min(hmin[a[i]],h[t]);
        hmin[b[i]]=min(hmin[b[i]],h[t]);
        if (t!=a[i]&&t!=b[i]) {
            adj2[a[i]].push_back({b[i],1});
            adj2[b[i]].push_back({a[i],1});
        }
    }
    dfs2(1,0);
    for (int i=2;i<=n;i++) {
        if (h[i]-hmin[i]>=2) {
            adj2[i].push_back({up[i][0],0});
            adj2[up[i][0]].push_back({i,0});
        }
    }
    memset(col,-1,sizeof(col));
    for (int u=2;u<=n;u++) {
        if (col[u]!=-1) continue;
        res++;
        col[u]=0;
        dfs3(u);
    }
    for (int i=1;i<=res;i++) {
        ans*=2;
        ans%=mod;
    }
    cout<<ans;
}
