#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
int res;
int c[N+5];
bool vis[N+5];
vector<int>team;
vector<set<int>>adj(N+5);
void dfs (int s) {
    for (auto i:adj[s]) {
        c[i]--;
        if (c[i]<k&&!vis[i]) {
            vis[i]=true;
            dfs(i);
        }
    }
}
int main() {
    freopen("TEAMK.INP","r",stdin);
    freopen("TEAMK.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
        c[u]++;
        c[v]++;
    }
    for (int i=1;i<=n;i++) {
        if (c[i]<k&&!vis[i]) {
            vis[i]=true;
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            res++;
            team.push_back(i);
        }
    }
    cout<<res<<endl;
    for (auto i:team) cout<<i<<' ';
}
