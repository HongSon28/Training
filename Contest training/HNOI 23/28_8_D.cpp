#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m,k;
vector<vector<pair<int,int>>>adj(N+5);
vector<vector<int>>d(N+5);
map<int,bool>mp[N+5];
struct dat{
    int u,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
int inf=1e9;
priority_queue<dat>pq;
void dij() {
    for (int i=1;i<=n;i++)
        for (int j=0;j<k;j++)
            d[i][j]=inf;
    d[1][0]=0;
    pq.push({1,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int u=t.u,du=t.d;
        if (du>d[u][k-1]) continue;
        for (auto p:adj[u]){
            int v=p.first,w=p.second;
            if (du+w<d[v][k-1]&&!mp[v][du+w]) {
                d[v][k-1]=du+w;
                mp[v][du+w]=true;
                sort(d[v].begin(),d[v].end());
                pq.push({v,du+w});
            }
        }
    }
    for (int i=0;i<k;i++) {
        if (d[n][i]==inf) {
            cout<<-1;
            return;
        }
    }
    for (int i=0;i<k;i++) cout<<d[n][i]<<' ';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int a,b,d;
        cin>>a>>b>>d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
    }
    for (int i=1;i<=n;i++) d[i].resize(k);
    dij();
}
