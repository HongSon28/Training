#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int res[N+5];
vector<vector<pair<int,int>>>adj(N+5);
void dfs(int u,int par,int col){
    res[u]=col;
    for (auto p:adj[u]) {
        int v=p.first,w=p.second;
        if (v==par) continue;
        int cur=col;
        if (w%2==1) cur=!col;
        dfs(v,u,cur);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        w%=2;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,0,1);
    for (int i=1;i<=n;i++) cout<<res[i]<<' ';
}
