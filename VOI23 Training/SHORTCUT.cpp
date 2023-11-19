#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long c[N+5],d[N+5],mn[N+5],t,res,sum,inf=1e18;
vector<vector<pair<int,long long>>>adj(N+5);
vector<vector<int>>adj2(N+5);
struct dat{
    long long u,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
void dij() {
    for (int i=2;i<=n;i++) d[i]=inf;
    priority_queue<dat>pq;
    pq.push({1,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int u=t.u;
        long long du=t.d;
        if (du!=d[u]) continue;
        for (auto p:adj[u]) {
            int v=p.first;
            long long w=p.second;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                mn[v]=u;
                pq.push({v,d[v]});
            } else if (d[v]==d[u]+w) {
                if (u<mn[v]) {
                    mn[v]=u;
                    pq.push({v,d[v]});
                }
            }
        }
    }
}
void dfs(int u,int par) {
    for (auto v:adj2[u]) {
        if (v==par) continue;
        dfs(v,u);
        c[u]+=c[v];
    }
}
int main() {
    freopen("SHORTCUT.INP","r",stdin);
    freopen("SHORTCUT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>t;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dij();
    for (int i=1;i<=n;i++) {
        adj2[i].push_back(mn[i]);
        adj2[mn[i]].push_back(i);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++) res=max(res,c[i]*d[i]-c[i]*t);
    cout<<res;
}
