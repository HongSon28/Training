#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m,k,x;
long long p[N+5];
long long d[N+5];
vector<vector<pair<long long,long long>>>adj(N+5);

int main() {
    cin>>n>>m>>k>>x;
    for (int i=1;i<=m;i++) {
        long long u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for (int i=1;i<=k;i++) cin>>p[i];

}
