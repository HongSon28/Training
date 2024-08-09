#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int n,k;
vector<int>grp[N+5];
vector<vector<int>>adj(N+5);
int h[N+5],up[N+5][LG+5];
void dfs(int u) {
    for (auto v:adj[u]){
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
            if ((k>>j)&1) u=up[u][j];
        }
    }
    if (u==v) return u;
    int k=__lg(h[u]);
    for (int j=LG;j>=0;j--) {
        if (up[u][j]!=up[v][j]) {
            u=up[u][j];
            v=up[v][j];
        }
    }
    return up[u][0];
}
int dist(int u,int v) {
    int p=lca(u,v);
    return h[u]+h[v]-2*h[p];
}
int calc(int n) {
    int a=grp[n][0];
    int b,c;
    int mx=INT_MIN;
    for (auto x:grp[n]) {
        int temp=dist(a,x);
        if (temp>mx) {
            mx=temp;
            b=x;
        }
    }
    mx=INT_MIN;
    for (auto x:grp[n]) {
        int temp=dist(b,x);
        if (temp>mx) {
            mx=temp;
            c=x;
        }
    }
    //cout<<b<<' '<<c<<' ';
    return dist(b,c);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        grp[x].push_back(i);
        if (y==0) continue;
        adj[y].push_back(i);
        adj[i].push_back(y);
    }
    dfs(1);
    for (int i=1;i<=k;i++) cout<<calc(i)<<'\n';
}
