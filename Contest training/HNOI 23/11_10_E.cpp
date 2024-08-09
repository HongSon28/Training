#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,s,p;
int a[N+5];
bool game[N+5],game2[N+5];
int vis[N+5];
vector<vector<int>>adj(N+5),adj2(N+5);
int timer,scc;
int low[N+5],num[N+5],label[N+5];
bool del[N+5];
stack<int>st;
int dp[N+5],val[N+5],res;
void dfs(int u) {
    num[u]=low[u]=++timer;
    st.push(u);
    for (auto v:adj[u]) {
        if (del[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        } else low[u]=min(low[u],num[v]);
    }
    if (low[u]==num[u]) {
        scc++;
        int v;
        do {
            v=st.top();
            st.pop();
            del[v]=true;
            label[v]=scc;
            val[scc]+=a[v];
            if (game[v]) game2[scc]=true;
        } while (v!=u);
    }
}
vector<int>revTopo;
void dfs_topo(int u) {
    vis[u]=1;
    for (auto v : adj2[u])
        if (!vis[v]) dfs_topo(v);
    revTopo.push_back(u);
    vis[u]=2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>s>>p;
    for (int u,i=1;i<=p;i++) {
        cin>>u;
        game[u]=true;
    }
    dfs(s);
    for (int u=1;u<=n;u++) {
        for (auto v:adj[u]) {
            int x=label[u],y=label[v];
            if (x==0||y==0||x==y) continue;
            adj2[x].push_back(y);
        }
    }
    dfs_topo(label[s]);
    dp[label[s]]=val[label[s]];
    reverse(revTopo.begin(),revTopo.end());
    for (auto u:revTopo) {
        for (auto v:adj2[u]) dp[v]=max(dp[v],dp[u]+val[v]);
        if (game2[u]) res=max(res,dp[u]);
    }
    cout<<res;
}
