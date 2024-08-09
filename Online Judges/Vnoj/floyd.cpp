#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,k;
vector<vector<pair<int,int>>>adj(N+5);
int d[N+5];
int trace[N+5];
void dijkstra(int s) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for (int i=1;i<=n;i++) d[i]=INT_MAX;
    d[s]=0;
    memset(trace,0,sizeof(trace));
    trace[s]=-1;
    pq.push({0,s});
    while (!pq.empty()) {
        pair<int,int>p=pq.top();
        pq.pop();
        int du=p.first,u=p.second;
        if (du!=d[u]) continue;
        for (auto i:adj[u]) {
            int v=i.first,c=i.second;
            if (d[u]+c<d[v]) {
                d[v]=d[u]+c;
                trace[v]=u;
                pq.push({d[v],v});
            }
        }
    }
}
void solve(int u,int v) {
    vector<int>vc;
    vc.push_back(v);
    while (trace[v]!=-1) {
        v=trace[v];
        vc.push_back(v);
    }
    cout<<vc.size()<<' ';
    reverse(vc.begin(),vc.end());
    for (auto i:vc) cout<<i<<' ';
    cout<<endl;
}
int main() {
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    while(k--) {
        int t,u,v;
        cin>>t>>u>>v;
        if (u==v) {
            if (t==0) cout<<1<<endl;
            else cout<<3<<' '<<u<<' '<<adj[u][0].first<<' '<<v<<endl;
        } else {
            dijkstra(u);
            if (t==0) cout<<d[v]<<endl;
            else solve(u,v);
        }
    }
}
