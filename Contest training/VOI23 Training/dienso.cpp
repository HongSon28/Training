#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,k;
int a[N+5],x[N+5];
vector<vector<int>>adj(N+5);
int dp[N+5][2],inf=1e6,cnt[N+5];
void dfs(int u,int par,int i) {
    cnt[u]=1;
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u,i+1);
        cnt[u]+=cnt[v];
    }
    if (a[u]!=-1) {
        if (a[u]<x[i]) {
            dp[u][0]=cnt[u];
            dp[u][1]=inf;
        } else if (a[u]==x[i]) {
            if (i==k) {
                dp[u][0]=0;
                dp[u][1]=0;
            } else if(i<k) {
                if (adj[u].size()==1&&u!=1) {
                    dp[u][0]=1;
                    dp[u][1]=inf;
                } else {
                    dp[u][0]=1;
                    dp[u][1]=inf;
                    int sum=0;
                    for (auto v:adj[u]) {
                        if (v==par) continue;
                        dp[u][0]+=dp[v][0];
                        sum+=min(dp[v][0],dp[v][1]);
                    }
                    for (auto v:adj[u]) {
                        if (v==par) continue;
                        dp[u][1]=min(dp[u][1],sum-min(dp[v][0],dp[v][1])+dp[v][1]+1);
                    }
                }
            }
        } else {
            dp[u][0]=0;
            dp[u][1]=inf;
        }
    } else {
        dp[u][0]=cnt[u];
        dp[u][1]=inf;
        if (i==k) {
            dp[u][0]=0;
            dp[u][1]=0;
        } else if (i<k) {
            if (adj[u].size()==1&&u!=1) {
                dp[u][0]=1;
                dp[u][1]=inf;
            } else {
                int c0=1;
                int sum=0;
                for (auto v:adj[u]) {
                    if (v==par) continue;
                    c0+=dp[v][0];
                    sum+=min(dp[v][0],dp[v][1]);
                }
                for (auto v:adj[u]) {
                    if (v==par) continue;
                    dp[u][1]=min(dp[u][1],sum-min(dp[v][0],dp[v][1])+dp[v][1]+1);
                    //cout<<u<<' '<<v<<' '<<sum<<' '<<min(dp[v][0],dp[v][1])<<' '<<dp[v][1]<<' '<<sum-min(dp[v][0],dp[v][1])+dp[v][1]+1<<endl;
                }
                dp[u][0]=min(dp[u][0],c0);
            }
         }
         if (x[i]!=m) {
            dp[u][0]=0;
         }
    }
    //cout<<u<<' '<<i<<' '<<cnt[u]<<' '<<dp[u][0]<<' '<<dp[u][1]<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=k;i++) cin>>x[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,1);
    cout<<dp[1][1]+1;
}
