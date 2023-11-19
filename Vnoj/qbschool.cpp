#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4;
vector<vector<pair<ll,ll>>>adj(N+5);
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
ll MX=1e16;
ll n,m;
ll k,u,v,l;
ll d[N+5];
ll c[N+5];
int main() {
    cin>>n>>m;
    for (int i=2;i<=n;i++)
        d[i]=MX;
    c[1]=1;
    q.push(make_pair(0,1));
    for (int i=1;i<=m;i++) {
        cin>>k>>u>>v>>l;
        if (k==1) adj[u].push_back(make_pair(v,l));
        else {
            adj[u].push_back(make_pair(v,l));
            adj[v].push_back(make_pair(u,l));
        }
    }
    while (!q.empty()) {
        pair<int,int> t=q.top();
        int u=t.second,du=t.first;
        q.pop();
        if (du>d[u]) continue;
        for (auto i:adj[u]) {
            int v=i.first,l=i.second;
            if (du+l<d[v]) {
                c[v]=c[u];
                d[v]=du+l;
                q.push(pair<int,int>(d[v],v));
            } else if (du+l==d[v]) {
                c[v]+=c[u];
            }
        }
    }
    cout<<d[n]<<' '<<c[n];
}
