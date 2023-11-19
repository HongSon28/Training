#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3;
int n;
vector<vector<int>>adj(N+5);
ll c[N+5],t[N+5];
ll inf=1e10+5;
ll dp[2][N+5][N+5],sum[N+5];
void dfs(int u,int par) {
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
    }
    for (int i=0;i<n;i++) {
        sum[i]=0;
        for (auto v:adj[u]) {
            if (v==par) continue;
            sum[i]+=dp[1][v][i];
        }
        sum[i]=min(sum[i],inf);
    }
    for (int i=0;i<t[u];i++) {
        if (sum[i]<inf) dp[0][u][i]=sum[i]+c[i];
    }
    for (auto v:adj[u]) {
        if (v==par) continue;
        for (int i=0;i<n-1;i++) {
            dp[0][u][i]=min(dp[0][u][i],dp[0][v][i+1]+sum[i]-dp[1][v][i]);
        }
    }
    for (int i=0;i<n;i++) dp[1][u][0]=min(dp[1][u][0],dp[0][u][i]);
    for (int i=1;i<n;i++) dp[1][u][i]=min(dp[1][u][0],sum[i-1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=0;i<n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=0;i<2;i++)
        for (int j=0;j<=n;j++)
            for (int k=0;k<=n;k++)
                dp[i][j][k]=inf;
    dfs(1,0);
    if (dp[1][1][0]>=inf) cout<<-1;
    else cout<<dp[1][1][0];
}
