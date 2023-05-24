#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
vector<vector<int>>adj(N+5);
int parent[N+5];
int c[N+5];
bool vis[N+5];
void dfs(int s) {
    vis[s]=true;
    for (auto i:adj[s]) {
        if (!vis[i]) {
            parent[i]=s;
            vis[i]=true;
            dfs(i);
        }
    }
}
int main() {
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    parent[1]=-1;
    dfs(1);
}
