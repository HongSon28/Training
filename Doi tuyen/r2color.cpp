#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m;
vector<vector<int>>adj(N+5);
int color[N+5],val[N+5],temp[N+5],change[N+5],cnt,res,cur,inf=1e8;
bool vis[2][N+5];
void dfs(int u,int c,int prev,int k) {
    if (vis[k][u]) {
        if (c!=change[u]) {
            cnt=inf;
        }
        return;
    }
    vis[k][u]=true;
    if (val[u]==0&&c!=color[u]) {
        cnt=inf;
    }
    if (val[u]==1&&c!=color[u]&&cnt!=inf) cnt++;
    change[u]=c;
    for (auto v:adj[u]) {
        if (v==prev) continue;
        if (c==1) dfs(v,2,u,k);
        else dfs(v,1,u,k);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>color[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>val[i];
    }
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        cur=inf;
        if (vis[0][i]||vis[1][i]) continue;
        cnt=0;
        dfs(i,1,0,0);
        cur=min(cur,cnt);
        cnt=0;
        dfs(i,2,0,1);
        cur=min(cur,cnt);
        if (cur==inf) res=inf;
        else if (res!=inf) res+=cur;
    }
    if (res==inf) cout<<-1;
    else cout<<res;
}
