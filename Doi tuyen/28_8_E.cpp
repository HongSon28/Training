#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n;
vector<vector<vector<pair<int,int>>>>adj(N+5);
int d[N+5][2];
struct dat{
    int u,c,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
int inf=1e9;
priority_queue<dat>pq;
void dij() {
    for (int i=1;i<=n;i++) d[i][0]=d[i][1]=inf;
    d[n][0]=d[n][1]=0;
    pq.push({n,0,0});
    pq.push({n,1,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int u=t.u,c=t.c,du=t.d;
        if (du!=d[u][c]) continue;
        if (c==0) {
            for (auto p:adj[u][1]) {
                int v=p.first,w=p.second;
                if (d[v][1]>d[u][c]+w) {
                    d[v][1]=d[u][c]+w;
                    pq.push({v,1,d[v][1]});
                }
            }
        } else {
            for (auto p:adj[u][0]) {
                int v=p.first,w=p.second;
                if (d[v][0]>d[u][c]+w) {
                    d[v][0]=d[u][c]+w;
                    pq.push({v,0,d[v][0]});
                }
            }
        }
    }
    int res=min(d[1][0],d[1][1]);
    cout<<res;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) adj[i].resize(2);
    int u;
    while (cin>>u) {
        int v,w1,w2;
        char l;
        cin>>v>>w1>>w2>>l;
        if (l=='M') {
            adj[u][0].push_back({v,w1});
            adj[v][1].push_back({u,w2});
        } else {
            adj[u][1].push_back({v,w1});
            adj[v][0].push_back({u,w2});
        }
    }
    dij();
}
