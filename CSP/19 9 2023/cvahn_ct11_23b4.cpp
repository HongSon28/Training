#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,k;
vector<int>center;
int d[N+5][N+5];
struct dat{
    int u,d;
    bool operator < (const dat &other) const {
        return d<other.d;
    }
};
priority_queue<dat>pq;
vector<vector<pair<int,int>>>adj(N+5);
struct Edge{
    int u,v,w;
    bool operator < (const Edge &other) const {
        return w<other.w;
    }
};
vector<Edge>edge;
int inf=1e9;
void dij(int s) {
    for (int i=0;i<=N;i++) d[s][i]=inf;
    d[s][s]=0;
    pq.push({s,0});
    while (!pq.empty()) {
        int u=pq.top().u,du=pq.top().d;
        pq.pop();
        if (du!=d[s][u]) continue;
        for (auto p:adj[u]){
            int v=p.first,w=p.second;
            if (du+w<d[s][v]) {
                d[s][v]=du+w;
                pq.push({v,du+w});
            }
        }
    }
}
int main() {
    cin>>n>>m>>k;
    for (int i=1;i<=k;i++) {
        int t;
        cin>>t;
        center.push_back(t);
    }
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (auto u:center) dij(u);
    for (int i=0;i<center.size();i++) {
        for (int j=0;j<i;j++) {
            edge.push_back({center[i],center[j],d[center[i]][center[j]]});
        }
    }
    sort(edge.begin(),edge.end());
    for (auto i:edge) cout<<i.u<<' '<<i.v<<' '<<i.w<<endl;
}
