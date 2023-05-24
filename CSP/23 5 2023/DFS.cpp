#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<vector<int>>adj(N+5);
bool vis[N+5];
int n,m;
int trace[N+5];
vector<int>res;
void dfs(int s) {
    for (int i=0;i<adj[s].size();i++) {
        if (!vis[adj[s][i]]) {
            vis[adj[s][i]]=true;
            trace[adj[s][i]]=s;
            dfs(adj[s][i]);
        }
    }
}
int main() {
    freopen("DFS.INP","r",stdin);
    freopen("DFS.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for (int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
    vis[1]=true;
    dfs(1);
    for (int i=n;i!=1;i=trace[i]) {
        res.push_back(trace[i]);
    }
    reverse(res.begin(),res.end());
    for (int i=0;i<res.size();i++) cout<<res[i]<<' ';
    cout<<n;
}
