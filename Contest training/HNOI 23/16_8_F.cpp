#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k;
int c[N+5];
long long res;
long long dp[N+5][2][2][2][2][2];
vector<vector<int>>adj(N+5);
long long dfs(int u,int c1,int c2,int c3,int c4,int c5) {
    if (dp[u][c1][c2][c3][c4][c5]!=-1) return dp[u][c1][c2][c3][c4][c5];
    long long ans=1;
    for (auto v:adj[u]) {
        //cout<<u<<' '<<v<<' '<<c[v]<<' '<<c2<<endl;
        if (c[v]==1) {
            if (c1==0) ans+=dfs(v,1,c2,c3,c4,c5);
        }
        else if (c[v]==2) {
            if (c2==0) ans+=dfs(v,c1,1,c3,c4,c5);
        }
        else if (c[v]==3) {
            if (c3==0) ans+=dfs(v,c1,c2,1,c4,c5);
        }
        else if (c[v]==4) {
            if (c4==0) ans+=dfs(v,c1,c2,c3,1,c5);
        }
        else {
            if (c5==0) ans+=dfs(v,c1,c2,c3,c4,1);
        }
    }
    dp[u][c1][c2][c3][c4][c5]=ans;
    return ans;
}
int main() {
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        if (c[i]==1)
            res+=dfs(i,1,0,0,0,0);
        else if (c[i]==2)
            res+=dfs(i,0,1,0,0,0);
        else if (c[i]==3)
            res+=dfs(i,0,0,1,0,0);
        else if (c[i]==4)
            res+=dfs(i,0,0,0,1,0);
        else
            res+=dfs(i,0,0,0,0,1);
    }
    cout<<res-n;
}
