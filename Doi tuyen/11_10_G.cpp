#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
vector<vector<int>>adj(N+5);
int n,m,mask;
int res,sum,mod=2021;
int dp[N+5];
int c[N+5];
void dfs(int u,int par) {
    if ((mask>>c[u])&1) dp[u]=0;
    else dp[u]=1;
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
        dp[u]*=dp[v]+1;
        dp[u]%=mod;
    }
    sum+=dp[u];
    dp[u]%=mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>c[i];
        c[i]--;
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (mask=0;mask<(1<<m);mask++) {
        sum=0;
        dfs(1,0);
        if (__builtin_popcount(mask)%2==1) sum=-sum;
        res+=sum;
        res%=mod;
    }
    res=(res+mod)%mod;
    cout<<res;
}
