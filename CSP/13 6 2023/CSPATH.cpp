#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
vector<vector<pair<ll,ll> > >adj(N+5);
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
ll mod=123456789;
ll MX=1e16;
ll n,m;
ll u,v,l;
ll d[N+5];
ll c[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CSPATH.INP","r",stdin);
    freopen("CSPATH.OUT","w",stdout);
    cin>>n>>m;
    for (int i=2;i<=n;i++)
        d[i]=MX;
    c[1]=1;
    q.push(make_pair(0,1));
    for (int i=1;i<=m;i++) {
        cin>>u>>v>>l;
        adj[u].push_back(make_pair(v,l));
        adj[v].push_back(make_pair(u,l));
    }
    while (!q.empty()) {
        pair<ll,ll> t=q.top();
        ll u=t.second,du=t.first;
        q.pop();
        if (du>d[u]) continue;
        for (auto i:adj[u]) {
            ll v=i.first,l=i.second;
            if (du+l<d[v]) {
                c[v]=c[u];
                c[v]%=mod;
                d[v]=du+l;
                q.push(pair<ll,ll>(d[v],v));
            } else if (du+l==d[v]) {
                c[v]+=c[u];
                c[v]%=mod;
            }
        }
    }
    //for (int i=1;i<=n;i++) cout<<d[i]<<' '<<c[i]<<endl;
    cout<<d[n]<<endl<<c[n];
}
