#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
int n,q,ans,k;
vector<vector<int>>adj(N+5);
int up[N+5][LG+5],h[N+5],a[N+5];
void dfs(int u) {
    for (auto v:adj[u]) {
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        for (int j=1;j<=LG;j++) up[v][j]=up[up[v][j-1]][j-1];
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
void solve1() {
    while (q--) {
        vector<int>v1,v2;
        int u,v;
        cin>>u>>v;
        u=(u+ans*k)%n+1;
        v=(v+ans*k)%n+1;
        int k=lca(u,v);
        while (h[u]!=h[k]) {
            for (auto v:adj[u]) {
                if (h[v]+1==h[u]) {
                    u=v;
                    v1.push_back(v);
                }
            }
        }
        while (h[v]!=h[k]) {
            for (auto u:adj[v]) {
                if (h[u]+1==h[v]) {
                    v=u;
                    v2.push_back(u);
                }
            }
        }
        for (auto u:v1) cout<<u<<' ';
        for (int i=v2.size()-1;i>=1;i--) cout<<v2[i]<< ' ';
    }
}
int main() {
    freopen("LOVESTORY.INP","r",stdin);
    freopen("LOVESTORY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if (n<=3000) {
        solve1();
        return 0;
    }
    while (q--) {
        int u,v;
        cin>>u>>v;
        u=(u+ans*k)%n+1;
        v=(v+ans*k)%n+1;
        int k=lca(u,v);
        int t=h[u]-h[k]+h[v]-h[k];
        if (t%2==0) ans=a[u]+1;
        else ans=1;
        cout<<ans<<'\n';
    }
}

