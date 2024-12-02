#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int t,n,m;
vector<pair<int,int>>adj[N+5];
struct ed{
    int u,v,w;
} edge[N*2+5];
namespace sub1{
    const int M=18;
    int res[M+5][M+5],inf=1e9;
    vector<int>va,vb;
    bool p[M+5];
    void solve() {
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) res[i][j]=inf;
        for (int mask=1;mask<(1<<n);mask++) {
            va.clear();
            vb.clear();
            for (int i=0;i<n;i++) {
                if ((mask>>i)&1) {
                    va.push_back(i);
                    p[i]=true;
                } else {
                    vb.push_back(i);
                    p[i]=false;
                }
            }
            int cur=0;
            for (int i=1;i<=m;i++) {
                if (p[edge[i].u]!=p[edge[i].v]) cur+=edge[i].w;
            }
            for (auto u:va)
                for (auto v:vb)
                    res[u][v]=min(res[u][v],cur);
        }
        if (t==1) {
            int ans=inf;
            for (int i=0;i<n;i++)
                for (int j=i+1;j<n;j++)
                    ans=min(ans,res[i][j]);
            cout<<ans;
        } else {
            long long ans=0;
            for (int i=0;i<n;i++) {
                for (int j=0;j<n;j++)
                    if (i!=j) ans+=res[i][j];
            }
            cout<<ans;
        }
    }
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   cin>>t>>n>>m;
   for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edge[i]={u,v,w};
   }
   sub1::solve();
}
/*
1 6 9
0 1 1
0 2 7
1 2 1
1 3 3
1 4 2
2 4 4
3 4 1
3 5 6
4 5 2
*/
