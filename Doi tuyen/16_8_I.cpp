#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
#define ll long long
ll n,m,k;
vector<vector<ll>>adj(N+5);
ll dist1[N+5][N+5];
ll dist2[N+5][N+5];
vector<pair<ll,ll>>edge;
ll dij(ll s,ll t,ll mx) {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    ll d[N+5];
    for (int i=1;i<=n;i++) d[i]=1e9;
    d[s]=0;
    pq.push({0,s});
    while(!pq.empty()) {
        pair<ll,ll>p=pq.top();
        pq.pop();
        ll du=p.first,u=p.second;
        if (d[u]!=du) continue;
        for (auto v:adj[u]) {
            if (dist2[u][v]-dist1[u][v]>mx) continue;
            ll c=dist1[u][v];
            if (d[u]+c<d[v]) {
                d[v]=d[u]+c;
                pq.push({d[v],v});
            }
        }
    }
    return d[t];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        ll u,v,p,q;
        cin>>u>>v>>p>>q;
        adj[u].push_back(v);
        adj[v].push_back(u);
        dist1[u][v]=dist1[v][u]=p;
        dist2[u][v]=dist2[v][u]=q;
        edge.push_back({u,v});
    }
    while (k--) {
        ll res=1e9;
        ll s,t;
        cin>>s>>t;
        for (auto p:edge) {
            ll u=p.first,v=p.second;
            ll temp=dist2[u][v]-dist1[u][v];
            dist1[u][v]=dist1[v][u]=dist2[u][v];
            res=min(res,dij(u,s,temp)+dij(v,t,temp)+dist2[u][v]);
            //cout<<u<<' '<<s<<' '<<dij(u,s,temp)<<endl<<v<<' '<<t<<' '<<dij(v,t,temp)<<endl;
            res=min(res,dij(v,s,temp)+dij(u,t,temp)+dist2[u][v]);
            //cout<<v<<' '<<s<<' '<<dij(v,s,temp)<<endl<<u<<' '<<t<<' '<<dij(u,t,temp)<<endl;
            dist1[u][v]-=temp;
            dist1[v][u]-=temp;
        }
        cout<<res<<'\n';
    }
}

