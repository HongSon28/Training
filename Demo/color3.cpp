#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
string s;
vector<vector<int>>adj(N+5);
bool vis[N+5][4];
void bfs(int u,int col) {
    queue<int>q;
    q.push({u,col})
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        if (s[i]=='R') vis[i][1]=true;
        else if (s[i]=='G') vis[i][2]=true;
        else vis[i][3]=true;
    }
    if (!vis[1][1]) bfs(1,1);
    if (!vis[1][2]) bfs(1,2);
    if (!vis[1][3]) bfs(1,3);
}
