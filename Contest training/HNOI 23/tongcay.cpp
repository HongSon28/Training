#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
long long mod=1e9+7,res;
vector<vector<pair<long long,long long>>>adj(N+5);
long long dist[N+5][N+5];
long long c[N+5];
vector<vector<long long>>st(N+5);
void dfs(int root,int u,int par) {
    for (auto p:adj[u]) {
        int v=p.first,w=p.second;
        if (v==par) continue;
        dist[root][v]=dist[root][u]+w;
        dist[root][v]%=mod;
        dfs(root,v,u);
    }
}
int main() {
    freopen("tongcay.inp","r",stdin);
    freopen("tongcay.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=1;i<=n;i++) dfs(i,i,0);
    for (int i=1;i<=m;i++) {
        int t;
        cin>>t;
        while (t--) {
            int u;
            cin>>u;
            st[i].push_back(u);
            c[u]++;
        }
    }
    for (int u=1;u<=n;u++) {
        for (int v=u;v<=n;v++) {
            res+=dist[u][v]*c[u]*c[v];
            //cout<<u<<' '<<v<<' '<<c[u]<<' '<<c[v]<<' '<<dist[u][v]<<endl;
            res%=mod;
        }
    }
    for (auto s:st) {
        for (int i=0;i<s.size();i++) {
            for (int j=i+1;j<s.size();j++) {
                res-=dist[s[i]][s[j]];
                res%=mod;
            }
        }
    }
    res=(res+mod)%mod;
    cout<<res;
}
