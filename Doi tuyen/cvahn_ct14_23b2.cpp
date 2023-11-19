#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
int dist[N+5][N+5],inf=1e9,t[N+5][N+5],trace[N+5][N+5];
int res=inf,city;
struct dat{
    int u,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
void dij(int s) {
    for (int i=1;i<=n;i++) dist[s][i]=inf;
    dist[s][s]=0;
    pq.push({s,0});
    while (!pq.empty()) {
        int u=pq.top().u,du=pq.top().d;
        pq.pop();
        if (du!=dist[s][u]) continue;
        for (int v=1;v<=n;v++) {
            if (t[u][v]==0) continue;
            if (du+t[u][v]<dist[s][v]) {
                trace[s][v]=u;
                dist[s][v]=du+t[u][v];
                pq.push({v,dist[s][v]});
            }
        }
    }
}
vector<int>tr;
void dij_trace(int s) {
    tr.clear();
    int t=city;
    while (t!=s) {
        tr.push_back(t);
        t=trace[s][t];
    }
    cout<<s<<' ';
    for (int i=tr.size()-1;i>=0;i--) cout<<tr[i]<<' ';
    cout<<'\n';
}
int main()  {
    freopen("HLD.INP","r",stdin);
    freopen("HLD.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>t[i][j];
    for (int i=1;i<=n;i++) dij(i);
    for (int u=1;u<=n;u++) {
        int cur=0;
        for (int v=1;v<=n;v++) cur=max(cur,dist[v][u]);
        if (cur<res) {
            res=cur;
            city=u;
        }
    }
    cout<<city<<' '<<res<<'\n';
    for (int i=1;i<=n;i++) {
        if (i==city) continue;
        dij_trace(i);
    }
}
/*
5
0 5 0 0 6
5 0 3 0 0
0 3 0 3 0
0 0 3 0 4
6 0 0 4 0
*/
