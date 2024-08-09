#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
long long k,s,t;
vector<vector<pair<long long,long long>>>adj(N+5);
long long a[N+5],d[N+5],inf=1e18;
struct dat{
    long long u,d;
    bool operator <(const dat &other) const{
        return d>other.d;
    }
};
priority_queue<dat>pq;
int main() {
    freopen("BKLR.INP","r",stdin);
    freopen("BKLR.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        d[i]=inf;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==j) continue;
            adj[i].push_back({j,(a[i]+a[j])%k});
        }
    }
    cin>>s>>t;
    d[s]=0;
    pq.push({s,0});
    while (!pq.empty()) {
        dat tt=pq.top();
        pq.pop();
        long long u=tt.u,du=tt.d;
        if (du!=d[u]) continue;
        if (u==t) break;
        for (auto p:adj[u]) {
            long long v=p.first,w=p.second;
            if (d[v]>du+w) {
                d[v]=du+w;
                pq.push({v,d[v]});
            }
        }
    }
    cout<<d[t];
}
