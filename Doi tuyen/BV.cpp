#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
vector<vector<int>>adj(N+5);
bool p[N+5];
int mx,ru,res;
int l[N+5],r[N+5];
void dfs(int u,int par,int h) {
    if (p[u]&&h>mx) {
        mx=h;
        ru=u;
    }
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u,h+1);
    }
}
void dfs1(int u,int par,int h) {
    l[u]=h;
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs1(v,u,h+1);
    }
}
void dfs2(int u,int par,int h) {
    r[u]=h;
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs2(v,u,h+1);
    }
}
int main() {
    //freopen("BV.INP","r",stdin);
    //freopen("BV.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (m--) {
        int x;
        cin>>x;
        p[x]=true;
    }
    dfs(1,0,0);
    mx=0;
    int u=ru;
    dfs(u,0,0);
    int v=ru;
    dfs1(u,0,0);
    dfs2(v,0,0);
    for (int i=1;i<=n;i++) {
        if (max(l[i],r[i])<=k) res++;
        //cout<<l[i]<<' '<<r[i]<<endl;
    }
    cout<<res;
}
