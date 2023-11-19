#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
int n,m;
vector<vector<pair<ll,ll>>>adj(N+5);
int k,q;
ll d[N+5];
ll MX=1e18;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>qu;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("NUCLEAR.INP","r",stdin);
    freopen("NUCLEAR.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) d[i]=MX;
    for (int i=1;i<=m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
    cin>>k;
    for (int i=1;i<=k;i++) {
        int g;
        cin>>g;
        d[g]=0;
        qu.push(make_pair(0,g));
    }
    while (!qu.empty()) {
        pair<ll,ll>t=qu.top();
        qu.pop();
        ll u=t.second,du=t.first;
        if (d[u]!=du) continue;
        for (auto i:adj[u]) {
            ll v=i.first,c=i.second;
            if (d[u]+c<d[v]) {
                d[v]=d[u]+c;
                qu.push(make_pair(d[v],v));
            }
        }
    }
    cin>>q;
    while (q--) {
        int u;
        cin>>u;
        cout<<d[u]<<' ';
    }
}
