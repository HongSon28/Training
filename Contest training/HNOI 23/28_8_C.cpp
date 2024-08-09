#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int dp[N+5];
int res;
vector<vector<pair<int,int>>>adj(N+5);
int dfs(int u) {
    if (dp[u]!=-1) return dp[u];
    int ans=0;
    for (auto p:adj[u]) {
        int v=p.first,w=p.second;
        ans=max(ans,dfs(v)+w);
    }
    dp[u]=ans;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) dp[i]=-1;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    for (int i=1;i<=n;i++) dfs(i);
    for (int i=1;i<=n;i++) res=max(res,dp[i]);
    cout<<res;
}
