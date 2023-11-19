#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m,s,t,res;
struct dat{
    long long v,h,d;
};
vector<vector<dat>>adj(N+5);
long long inf=1e18,d[N+5];
struct dat2{
    long long u,d;
    bool operator < (const dat2 &other) const {
        return d>other.d;
    }
};
priority_queue<dat2>pq;
void dij(long long mx) {
    for (int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    pq.push({s,0});
    while (!pq.empty()) {
        dat2 temp=pq.top();
        pq.pop();
        long long u=temp.u,du=temp.d;
        if (du!=d[u]) continue;
        for (auto t:adj[u]) {
            long long v=t.v,h=t.h,w=t.d;
            if (h<mx) continue;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({v,d[v]});
            }
        }
    }
}
vector<int>v;
int tr[N+5];
void trace(long long res) {
    for (int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    pq.push({s,0});
    while (!pq.empty()) {
        dat2 temp=pq.top();
        pq.pop();
        long long u=temp.u,du=temp.d;
        if (du!=d[u]) continue;
        for (auto t:adj[u]) {
            long long v=t.v,h=t.h,w=t.d;
            if (h<res) continue;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                tr[v]=u;
                pq.push({v,d[v]});
            }
        }
    }
    while (t!=s) {
        v.push_back(t);
        t=tr[t];
    }
    v.push_back(t);
    reverse(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for (auto i:v) cout<<i<<' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("TUNNEL.INP","r",stdin);
    freopen("TUNNEL.OUT","w",stdout);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++) {
        int u,v,h,d;
        cin>>u>>v>>h>>d;
        adj[u].push_back({v,h,d});
        adj[v].push_back({u,h,d});
    }
    long long lo=1,hi=1e9;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        dij(mid);
        if (d[t]!=inf) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    trace(res);
}
