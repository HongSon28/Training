#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long s[N+5],dp[N+5],res=LLONG_MIN;
vector<vector<int>>adj(N+5);
void dfs(int u,int par) {
    dp[u]=s[u];
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
        dp[u]=max(dp[u],dp[v]+s[u]);
    }
    res=max(res,dp[u]);
}
void dfs2(int u,int par) {
    long long mx1=-1e16,mx2=-1e16;
    for (auto v:adj[u]) {
        if (v==par) continue;
        if (dp[v]>mx2) mx2=dp[v];
        if (mx2>mx1) swap(mx1,mx2);
        dfs(v,u);
    }
    res=max(res,s[u]+mx1+mx2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    cout<<res;
}
