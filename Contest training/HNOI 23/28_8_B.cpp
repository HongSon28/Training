#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m;
vector<vector<vector<pair<int,int>>>>adj(N+5);
int d[N+5][2];
struct dat{
    int u,c,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
int inf=1e9;
priority_queue<dat>pq;
void dij() {
    for (int i=1;i<=n;i++) d[i][0]=d[i][1]=inf;
    d[1][0]=d[1][1]=0;
    pq.push({1,0,0});
    pq.push({1,1,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int u=t.u,c=t.c,du=t.d;
        if (du!=d[u][c]) continue;
        if (c==0) {
            for (auto p:adj[u][1]) {
                int v=p.first,w=p.second;
                if (d[v][1]>d[u][c]+w) {
                    d[v][1]=d[u][c]+w;
                    pq.push({v,1,d[v][1]});
                }
            }
        } else {
            for (auto p:adj[u][0]) {
                int v=p.first,w=p.second;
                if (d[v][0]>d[u][c]+w) {
                    d[v][0]=d[u][c]+w;
                    pq.push({v,0,d[v][0]});
                }
            }
        }
    }
    int res=min(d[n][0],d[n][1]);
    if (res==inf) cout<<-1;
    else cout<<res;
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) adj[i].resize(2);
    for (int i=1;i<=m;i++) {
        int u,v,k,c;
        cin>>u>>v>>k>>c;
        adj[u][c].push_back({v,k});
        adj[v][c].push_back({u,k});
    }
    dij();
}
