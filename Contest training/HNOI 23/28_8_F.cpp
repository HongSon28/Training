#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,s,t,m;
vector<vector<pair<int,int>>>water(N+5),land(N+5);
vector<vector<pair<int,int>>>adj(2*N+5);
int d_land[N+5],d_water[N+5];
int inf=1e9+5,ans;
void dij_land() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for (int i=1;i<=n;i++) d_land[i]=inf;
    d_land[t]=0;
    pq.push({0,t});
    while (!pq.empty()) {
        int u=pq.top().second;
        int du=pq.top().first;
        pq.pop();
        if (du!=d_land[u]) continue;
        for (auto p:land[u]) {
            int v=p.first,w=p.second;
            if (d_land[v]>d_land[u]+w) {
                d_land[v]=d_land[u]+w;
                pq.push({d_land[v],v});
            }
        }
    }
}
void dij_water() {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for (int i=1;i<=n;i++) d_water[i]=inf;
    d_water[t]=0;
    pq.push({0,t});
    while (!pq.empty()) {
        int u=pq.top().second;
        int du=pq.top().first;
        pq.pop();
        if (du!=d_water[u]) continue;
        for (auto p:water[u]) {
            int v=p.first,w=p.second;
            if (d_water[v]>d_water[u]+w) {
                d_water[v]=d_water[u]+w;
                pq.push({d_water[v],v});
            }
        }
    }
}
int vis[2*N+5];
bool cycle=false;
void dfs(int u) {
    vis[u]=1;
    for (auto p:adj[u]) {
        int v=p.first;
        if (vis[v]==0) dfs(v);
        else if (vis[v]==1) {
            cycle=true;
            return;
        }
    }
    vis[u]=2;
}
int res[2*N+5];
int solve(int u) {
    if (res[u]!=-1) return res[u];
    if (u==t||u==t+n) {
        res[u]=0;
        return 0;
    }
    int ans=-inf;
    for (auto p:adj[u]) {
        int v=p.first,w=p.second;
        ans=max(ans,w+solve(v));
    }
    res[u]=ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s>>t;
    cin>>m;
    while (m--) {
        int u,v,d;
        cin>>u>>v>>d;
        land[u].push_back({v,d});
        land[v].push_back({u,d});
    }
    dij_land();
    cin>>m;
    while (m--) {
        int u,v,d;
        cin>>u>>v>>d;
        water[u].push_back({v,d});
        water[v].push_back({u,d});
    }
    dij_water();
    for (int u=1;u<=n;u++) {
        for (auto p:land[u]) {
            int v=p.first,d=p.second;
            if (d_land[u]>d_land[v]) {
                adj[u+n].push_back({v,d});
                //cout<<u+n<<' '<<v<<endl;
            }
        }
    }
    for (int u=1;u<=n;u++) {
        for (auto p:water[u]) {
            int v=p.first,d=p.second;
            if (d_water[u]>d_water[v]) {
                adj[u].push_back({v+n,d});
                //cout<<u<<' '<<v+n<<endl;
            }
        }
    }
    dfs(s+n);
    if (cycle) {
        cout<<-1;
        return 0;
    }
    memset(res,-1,sizeof(res));
    cout<<solve(s+n);
}
