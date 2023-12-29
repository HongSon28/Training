#include<bits/stdc++.h>
using namespace std;
const int N=5000;
vector<pair<int,int>>edge;
bool cut[N+5][N+5],cut2[N+5];
long long f[N+5][N+5],g[N+5][N+5];
int n,m;
long long a,b,c,mod=1e9+7,res;
vector<vector<int>>adj(N+5);
bool vis[N+5];
void dfs(int u) {
    vis[u]=true;
    for (auto v:adj[u]) {
        if (cut[u][v]||cut2[v]||vis[v]) continue;
        dfs(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("CHAMELEON.INP","r",stdin);
    freopen("CHAMELEON.OUT","w",stdout);
    cin>>n>>m>>a>>b>>c;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	edge.push_back({u,v});
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (auto p:edge) {
    	int u=p.first,v=p.second;
        cut[u][v]=true;
        cut[v][u]=true;
        for (int i=1;i<=n;i++) {
            memset(vis,false,sizeof(vis));
            dfs(i);
            for (int j=i+1;j<=n;j++) {
                if (!vis[j]) f[i][j]++;
            }
        }
        cut[u][v]=false;
        cut[v][u]=false;
    }
    for (int x=1;x<=n;x++) {
        cut2[x]=true;
        for (int i=1;i<=n;i++) {
            if (i==x) continue;
            memset(vis,false,sizeof(vis));
            dfs(i);
            for (int j=i+1;j<=n;j++) {
                if (!vis[j]) g[i][j]++;
            }
        }
        cut2[x]=false;
    }
    for (int i=1;i<n;i++) {
        for (int j=i+1;j<=n;j++) {
            g[i][j]++;
            long long temp=(((f[i][j]%mod)*a)%mod+((g[i][j]%mod)*b)%mod)%mod;
            if (c==1) {
                res+=temp;
                res%=mod;
            }
            else {
                res+=(temp*temp)%mod;
                res%=mod;
            }
        }
    }
    cout<<res;
}
