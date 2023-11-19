#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int N=50;
int k,n,s,res;
bool a[N+1][N+1];
int dp[N+1][N+1][N+1][N+1];
vector<vector<int>>adj(N+1);
int matchx[N+1],matchy[N+1];
bool vis[N+1];
bool dfs(int u) {
    if (vis[u]) return false;
    vis[u]=true;
    for (auto v:adj[u]) {
        if (matchx[v]==-1||dfs(matchx[v])) {
            matchx[v]=u;
            matchy[u]=v;
            return true;
        }
    }
    return false;
}
void solve1() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (!a[i][j]) continue;
            adj[i].push_back(j);
        }
    }
    memset(matchx,-1,sizeof(matchx));
    memset(matchy,-1,sizeof(matchy));
    for (int i=1;i<=n;i++) {
        if (matchy[i]==-1) {
            memset(vis,false,sizeof(vis));
            dfs(i);
        }
    }
    for (int i=1;i<=n;i++) res+=(matchx[i]!=-1);
    cout<<res;
}
int f(int u,int v,int x,int y) {
    if (dp[u][v][x][y]!=-1) return dp[u][v][x][y];
    if (u==x&&v==y) {
        dp[u][v][x][y]=a[u][v];
        return a[u][v];
    }
    int ans=max(y-v+1,x-u+1);
    for (int i=u;i<x;++i) ans=min(ans,f(u,v,i,y)+f(i+1,v,x,y));
    for (int i=v;i<y;++i) ans=min(ans,f(u,v,x,i)+f(u,i+1,x,y));
    dp[u][v][x][y]=ans;
    return ans;
}
void solve2() {
    memset(dp,-1,sizeof(dp));
    cout<<f(1,1,n,n);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>n>>s;
    for (int i=1;i<=s;++i) {
        int x,y;
        cin>>x>>y;
        a[x][y]=true;
    }
    if (k==1) solve1();
    else solve2();
}
