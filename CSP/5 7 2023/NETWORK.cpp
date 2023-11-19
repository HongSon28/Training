#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000;
ll n,m;
ll f[N+5];
ll d[N+5][N*N+5];
ll inf=1e18;
vector<vector<pair<int,int>>>adj(N+5);
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>f[i];
    for (int i=1;i<=m;i++) {
        ll u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=N*N;j++) d[i][j]=inf;
    }
    d[1][f[1]]=0;
}
