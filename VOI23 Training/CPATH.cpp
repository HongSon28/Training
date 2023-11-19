#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
int n,m;
vector<vector<pair<int,int>>>adj(N+5),adj2(N+5);
int h[N+5];
pair<int,int> trace[N+5];
queue<int>q;
bool vis[N+5];
void bfs() {
    q.push(n);
    vis[n]=true;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (auto [v,w]:adj[u]) {
            if (vis[v]) continue;
            h[v]=h[u]+1;
            vis[v]=true;
            q.push(v);
        }
    }
}
vector<int>res;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    bfs();
    for (int u=1;u<=n;u++) {
        for (auto [v,w]:adj[u]) {
            if (vis[u]&&vis[v]&&h[v]==h[u]-1) adj2[u].push_back({v,w});
        }
    }
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    q.push(1);
    while (!q.empty()) {
        int mx=INT_MAX;
        vector<pair<int,int>>cur;
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for (auto [v,w]:adj2[u]) {
                if (w<mx) mx=w;
                cur.push_back({v,w});
            }
        }
        for (auto [v,w]:cur) {
            if (w==mx&&!vis[v]) {
                q.push(v);
                vis[v]=true;
            }
        }
        res.push_back(mx);
    }
    res.pop_back();
    cout<<res.size()<<'\n';
    for (auto i:res) cout<<i<<' ';
}
