#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int cnt;
vector<vector<int>>adj(N+5);
vector<pair<int,int>>lst;
int connected[N+5][N+5];
bool vis[N+5];
void bfs() {
    memset(vis,false,sizeof(vis));
    queue<int>q;
    q.push(1);
    vis[1]=true;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (auto v:adj[u]) {
            if (connected[u][v]>0&&!vis[v]) {
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        lst.push_back({u,v});
        adj[u].push_back(v);
        adj[v].push_back(u);
        connected[u][v]++;
        connected[v][u]++;
    }
    for (auto i:lst) {
        int u=i.first,v=i.second;
        connected[u][v]--;
        connected[v][u]--;
        bfs();
        bool flag=true;
        for (int j=1;j<=n;j++) {
            if (!vis[j]) flag=false;
        }
        if (!flag) cnt++;
        connected[u][v]++;
        connected[v][u]++;
    }
    cout<<cnt;
}
