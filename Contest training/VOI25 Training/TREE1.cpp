#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5];
vector<int>adj[N+5];
namespace sub1{
    int h[N+5],p[N+5];
    void dfs(int u,int par) {
        h[u]=h[par]+1;
        p[u]=par;
        for (auto v:adj[u]) {
            if (v==par) continue;
            dfs(v,u);
        }
    }
    int dp[N+5][3];
    void solve() {
        dfs(1,0);
        while (q--) {
            int u,v;
            cin>>u>>v;
            vector<int>v1,v2;
            v1.push_back(0);
            if (h[u]<h[v]) swap(u,v);
            while (h[u]>h[v]) {
                v1.push_back(a[u]);
                u=p[u];
            }
            while (u!=v) {
                v1.push_back(a[u]);
                v2.push_back(a[v]);
                u=p[u];
                v=p[v];
            }
            v1.push_back(a[u]);
            reverse(v2.begin(),v2.end());
            for (auto x:v2) v1.push_back(x);
            int m=v1.size()-1,res=0;
            for (int i=1;i<=m;i++) {
                dp[i][1]=1;
                dp[i][2]=0;
                for (int j=1;j<i;j++) {
                    if (v1[i]>v1[j]) dp[i][1]=max(dp[i][1],dp[j][2]+1);
                    else if (v1[i]<v1[j]) dp[i][2]=max(dp[i][2],dp[j][1]+1);
                }
                res=max(res,dp[i][2]);
                //cout<<v1[i]<<' ';
            }
            cout<<res+1<<'\n';
        }
    }
}
namespace sub2{
    const int LG=17;
    int up[N+5][LG+5],cnt[N+5][LG+5];
    int h[N+5];
    void dfs(int u,int par) {
        h[u]=h[par]+1;
        for (auto v:adj[u]) {
            if (v==par) continue;
            up[v][0]=u;
            cnt[v][0]=(a[v]<a[u]);
            for (int i=1;i<=LG;i++) {
                up[v][i]=up[up[v][i-1]][i-1];
                cnt[v][i]=cnt[v][i-1]+cnt[up[v][i-1]][i-1];
            }
            dfs(v,u);
        }
    }
    void solve() {
        dfs(1,0);
        while (q--) {
            int u,v;
            cin>>u>>v;
            int res=0;
            if (h[v]!=h[u]) {
                if (h[u]<h[v]) swap(u,v);
                int k=h[u]-h[v];
                for (int i=0;(1<<i)<=k;i++) {
                    if (k>>i&1) {
                        res+=cnt[u][i];
                        u=up[u][i];
                    }
                }
            }
            for (int i=LG;i>=0;i--) {
                if (up[u][i]!=up[v][i]) {
                    res+=cnt[u][i]+cnt[v][i];
                    u=up[u][i];
                    v=up[v][i];
                }
            }
            int k;
            //cout<<res<<' '<<u<<' '<<v<<endl;
            if (u!=v) {
                res+=cnt[u][0]+cnt[v][0];
                k=up[u][0];
            } else k=u;
            res*=2;
            if (a[k]==1) res++;
            else res--;
            cout<<max(res,1)<<'\n';
        }
    }
}
int main() {
    freopen("TREE.INP","r",stdin);
    freopen("TREE.ANS","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sub2::solve();
}

