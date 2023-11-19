#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
const int N=2e5;
ll d[N+5];
vector<vector<pair<ll,ll>>>adj(N+5);
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
int main() {
    freopen("DIJ.INP","r",stdin);
    freopen("DIJ.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for (int i=1;i<=n;i++) d[i]=1e18;
    d[k]=0;
    pq.push({0,k});
    while(!pq.empty()) {
        pair<ll,ll>p=pq.top();
        pq.pop();
        ll du=p.first,u=p.second;
        if (d[u]!=du) continue;
        for (auto i:adj[u]) {
            ll v=i.first,c=i.second;
            if (d[u]+c<d[v]) {
                d[v]=d[u]+c;
                pq.push({d[v],v});
            }
        }
    }
    cout<<d[n];
}
