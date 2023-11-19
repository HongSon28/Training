#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
ll MX=1e18;
int n,m;
vector<vector<pair<ll,ll>>>adj(N+5);
ll d[N+5];
int main() {
    freopen("DIJKSTRA.INP","r",stdin);
    freopen("DIJKSTRA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
    }
    for (int i=2;i<=n;i++) d[i]=MX;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,1});
    while (!q.empty()) {
        pair<ll,ll> t=q.top();
        q.pop();
        for (auto i:adj[t.second]) {
            if (d[t.second]+i.second<d[i.first]) {
                d[i.first]=d[t.second]+i.second;
                q.push(make_pair(d[i.first],i.first));
            }
        }
    }
    if (d[n]==MX) cout<<-1;
    else cout<<d[n];
}
