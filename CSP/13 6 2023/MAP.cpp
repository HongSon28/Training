#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000;
ll n,m;
struct dat{
    ll v,w,t;
};
struct ver{
    ll d,u,t;
    bool operator < (const ver& other) const
    {
        return other.d > d;
    }
};
ll MX=1e18;
ll d[N+5];
vector<vector<dat>>adj(N+5);
priority_queue<ver>q;
int main() {
    freopen("MAP.INP","r",stdin);
    freopen("MAP.OUT","w",stdout);
    cin>>n>>m;
    for (int i=2;i<=n;i++) d[i]=MX;
    for (int i=1;i<=m;i++) {
        ll u,v,w,t;
        cin>>u>>v>>w>>t;
        adj[u].push_back({v,w,t});
        adj[v].push_back({u,w,t});
    }
    q.push({0,1,0});
    while (!q.empty()) {
        ver p=q.top();
        q.pop();
        ll u=p.u,t=p.t;
        if (d[u]!=p.d) continue;
        for (auto i:adj[u]) {
            ll w=i.w,ti=i.t,v=i.v;
            if (d[u]+w+ti*t<d[v]) {
                d[v]=d[u]+w+ti*t;
                q.push({d[v],v,t+1});
            }
        }
    }
    if (d[n]==MX) cout<<-1;
    else cout<<d[n];
}
