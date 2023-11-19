#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5;
int n,m;
int t[N+5];
vector<vector<pair<ll,ll>>>adj(N+5);
ll d[N+5],inf=1e18,res=-1;
struct dat{
    ll u,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
void dij() {
    for (int i=1;i<=n;i++) d[i]=inf;
    for (int i=1;i<=n;i++) {
        if (t[i]==1) {
            d[i]=0;
            pq.push({i,0});
        }
    }
    while (!pq.empty()) {
        ll u=pq.top().u,du=pq.top().d;
        pq.pop();
        if (du!=d[u]) continue;
        for (auto t:adj[u]) {
            ll v=t.first,w=t.second;
            if (d[v]>du+w) {
                d[v]=du+w;
                pq.push({v,d[v]});
            }
        }
    }
}
bool vis[N+5],block[N+5];
int cnt;
bool connected() {
    bool vis2[N+5];
    int cur=0;
    queue<ll>q;
    memset(vis2,false,sizeof(vis2));
    for (int i=1;i<=n;i++)
        if (t[i]==1&&!block[i]) {
            q.push(i);
            vis2[i]=true;
            cur=1;
            break;
        }
    while (!q.empty()) {
        ll u=q.front();
        q.pop();
        for (auto p:adj[u]) {
            ll v=p.first;
            if (vis2[v]) continue;
            if (block[v]) continue;
            if (t[v]==1) cur++;
            vis2[v]=true;
            q.push(v);
        }
    }
    return (cnt==cur);
}
bool check(ll mx) {
    queue<ll>q;
    memset(vis,false,sizeof(vis));
    memset(block,false,sizeof(block));
    vis[0]=true;
    q.push(0);
    while (!q.empty()) {
        ll u=q.front();
        q.pop();
        for (auto p:adj[u]) {
            int v=p.first;
            if (vis[v]) continue;
            if (t[v]==1) return false;
            if (d[v]<=mx) {
                block[v]=true;
                continue;
            }
            q.push(v);
            vis[v]=true;
        }
    }
    return connected();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>t[i];
        if (t[i]==1) cnt++;
    }
    for (int i=1;i<=m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        if (t[u]==-1) u=0;
        if (t[v]==-1) v=0;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dij();
    ll lo=0,hi=1e18;
    while (lo<=hi) {
        ll mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}
