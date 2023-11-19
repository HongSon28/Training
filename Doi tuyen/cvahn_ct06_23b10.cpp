#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n;
int dp[N+5];
vector<vector<pair<int,int>>>adj(N+5);
void dfs(int u,int par) {
    int cost=0,sum=0;
    for (auto p:adj[u]) {
        int v=p.first,w=p.second;
        if (v==par) continue;
        dfs(v,u);
        cost=w+dp[v];
        if (cost<=0) continue;
        sum+=cost;
    }
    dp[u]=sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MAXTREE.INP","r",stdin);
    freopen("MAXTREE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for (int i=1;i<=n;i++) {
        if (adj[i].size()==1) {
            dfs(i,0);
            break;
        }
    }
    cout<<*max_element(dp+1,dp+1+n);
}
