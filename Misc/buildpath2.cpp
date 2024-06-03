#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,res,mx,cur;
vector<vector<int>>adj(N+5);
vector<pair<int,int>>edge;
bool block[N+5][N+5];
int dist[N+5];
void dfs(int u,int par) {
    if (dist[u]>cur) {
        cur=dist[u];
        mx=u;
    }
    for (auto v:adj[u]) {
        if (v==par) continue;
        if (block[u][v]) continue;
        dist[v]=dist[u]+1;
        dfs(v,u);
    }
}
int d(int u) {
    memset(dist,0,sizeof(dist));
    cur=0;
    mx=u;
    dfs(u,0);
    memset(dist,0,sizeof(dist));
    cur=0;
    dfs(mx,0);
    return dist[mx];
}
int main() {
    //freopen("buildpath.inp","r",stdin);
    //freopen("buildpath2.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({u,v});
    }
    for (auto p:edge) {
        int u=p.first,v=p.second;
        block[u][v]=block[v][u]=true;
        res=max(res,d(u)+d(v)+1);
        block[u][v]=block[v][u]=false;
    }
    cout<<res;
}

