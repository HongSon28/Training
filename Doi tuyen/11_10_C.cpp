#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<vector<int>>adj(N+5),edge(N+5),dst(N+5);
map<pair<int,int>,int>mp;
struct tri{
    int a,b,c;
} triangle[N+5];
int cnt,n;
int dp[N+5][2];
void dfs(int u,int par) {
    dp[u][0]=0;
    dp[u][1]=1;
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
        int t1=dp[u][0]+min(dp[v][0],dp[v][1])+1;
        int t2=dp[u][1]+min(dp[v][0]+1,dp[v][1]);
        dp[u][1]=min(t1,t2);
        dp[u][0]+=dp[v][1];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n-3;i++) {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        if (u>v) swap(u,v);
        mp[{u,v}]=i;
    }
    for (int i=1;i<=n;i++) {
        int l=i-1,r=i+1;
        if (l==0) l=n;
        if (r==n+1) r=1;
        edge[i].push_back(l);
        edge[i].push_back(r);
    }
    for (int i=1;i<=n;i++) {
        sort(edge[i].begin(),edge[i].end());
        for (int j=0;j<edge[i].size()-1;j++) {
            int b=edge[i][j],c=edge[i][j+1];
            if (b>c) swap(b,c);
            if (i>b||i>c) continue;
            triangle[++cnt]={i,b,c};
            dst[mp[{i,b}]].push_back(cnt);
            dst[mp[{i,c}]].push_back(cnt);
            dst[mp[{b,c}]].push_back(cnt);
        }
    }
    for (int i=1;i<n-2;i++) {
        int u=dst[i][0];
        int v=dst[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<dp[1][1];
}
