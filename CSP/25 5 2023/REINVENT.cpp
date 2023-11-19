#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,x;
bool vis[N+5];
vector<vector<int>>adj(N+5);
int dist[N+5];
int par[N+5];
int res=INT_MAX;
struct dat{
    int ver,par,dis;
};
int main() {
    freopen("REINVENT.INP","r",stdin);
    freopen("REINVENT.OUT","w",stdout);
    cin>>n>>m>>x;
    for (int i=1;i<=n;i++) dist[i]=N+5;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=x;i++) {
        int t;
        cin>>t;
        dist[t]=0;
        par[t]=t;
        adj[0].push_back(t);
    }
    queue<dat>q;
    vis[0]=true;
    for (auto i:adj[0]) {
        vis[i]=true;
        q.push({i,i,0});
    }
    while (!q.empty()) {
        dat t=q.front();
        q.pop();
        for (auto i:adj[t.ver]) {
            if (!vis[i]) {
                vis[i]=true;
                if (dist[i]>t.dis+1) {
                    dist[i]=t.dis+1;
                    par[i]=t.par;
                }
                q.push({i,t.par,t.dis+1});
            } else {
                if (par[i]!=t.par) {
                    //cout<<t.ver<<' '<<i<<' '<<dist[i]<<' '<<t.dis+1<<endl;
                    res=min(res,dist[i]+t.dis+1);
                    if (dist[i]>t.dis+1) {
                        dist[i]=t.dis+1;
                        par[i]=t.par;
                    }
                }
            }
        }
    }
    cout<<res;
}
