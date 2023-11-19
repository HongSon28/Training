#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=250;
int n,m;
vector<vector<ll>>adj(N+5);
ll a[N+5][N+5];
ll d[N+5];
ll res,base;
ll MX=1e18;
void dijkstra() {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    q.push({0,1});
    for (int i=2;i<=n;i++) d[i]=MX;
    while (!q.empty()) {
        pair<ll,ll>t=q.top();
        q.pop();
        ll du=t.first,u=t.second;
        if (d[u]!=du) continue;
        for (auto v:adj[u]) {
            if (d[u]+a[u][v]<d[v]) {
                d[v]=d[u]+a[u][v];
                q.push({d[v],v});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("X2CANXI.INP","r",stdin);
    freopen("X2CANXI.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        ll u,v,wi;
        cin>>u>>v>>wi;
        a[u][v]=a[v][u]=wi;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dijkstra();
    base=d[n];
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++) {
            if (a[i][j]!=0) {
                a[i][j]*=2;
                a[j][i]*=2;
                dijkstra();
                res=max(res,d[n]-base);
                a[i][j]/=2;
                a[j][i]/=2;
            }
        }
    }
    cout<<res;
}
