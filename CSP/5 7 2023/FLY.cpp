#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5;
ll n,m,k;
ll res=1e18;
vector<vector<pair<ll,ll>>>adj(N+5);
ll d[N+5][2];
struct dat{
    ll d,u,cnt;
    bool operator < (const dat &others) const {
        return d>others.d;
    }
};
priority_queue<dat>pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("FLY.INP","r",stdin);
    freopen("FLY.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v,c));
    }
    for (int i=1;i<=n;i++) {
        d[i][0]=d[i][1]=1e18;
    }
    d[1][0]=0;
    pq.push({0,1,0});
    while (!pq.empty()) {
        dat p=pq.top();
        pq.pop();
        if (p.d!=d[p.u][p.cnt]) continue;
        for (auto i:adj[p.u]) {
            ll v=i.first,w=i.second;
            if(d[v][p.cnt]>d[p.u][p.cnt]+w) {
                d[v][p.cnt]=d[p.u][p.cnt]+w;
                pq.push({d[v][p.cnt],v,p.cnt});
            }
            if (p.cnt==0&&d[v][1]>d[p.u][0]+w/2) {
                d[v][1]=d[p.u][0]+w/2;
                pq.push({d[v][1],v,1});
            }
        }
    }
    cout<<min(d[n][0],d[n][1]);
}

