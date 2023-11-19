#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
struct edge{
    int v,t,h;
};
vector<vector<edge>>adj(N+5);
int k,n,m,a,b,inf=1e9;
int d[N+5][205];
struct dat{
    int u,h,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
int res=inf;
int main() {
    freopen("ROBINSON.INP","r",stdin);
    freopen("ROBINSON.OUT","w",stdout);
    cin>>k>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v,t,h;
        cin>>u>>v>>t>>h;
        adj[u].push_back({v,t,h});
        adj[v].push_back({u,t,h});
    }
    cin>>a>>b;
    for (int i=0;i<=200;i++)
        for (int j=0;j<=N;j++)
            d[j][i]=inf;
    d[a][0]=0;
    pq.push({a,0,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int u=t.u,du=t.d,h=t.h;
        if (d[u][h]!=du) continue;
        for (auto p:adj[u]) {
            int v=p.v,t=p.t,hh=p.h;
            if (h+hh<k&&d[v][h+hh]>du+t) {
                d[v][h+hh]=du+t;
                pq.push({v,h+hh,du+t});
            }
        }
    }
    for (int i=0;i<k;i++) res=min(res,d[b][i]);
    if (res==inf) cout<<-1;
    else cout<<res;
}
