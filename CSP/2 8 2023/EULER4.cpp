#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m;
vector<vector<int>>adj(N+5);
vector<vector<int>>v(N+5);
long long a[N+5];
long long h[N+5],st[N+5],en[N+5],tour[N+5];
long long timer;
void dfs(int u,int par) {
    h[u]=h[par]+1;
    timer++;
    st[u]=timer;
    tour[timer]=u;
    for (auto v:adj[u]) {
        if (v!=par) {
            dfs(v,u);
        }
    }
    en[u]=timer;
}
int main() {
    freopen("EULER4.INP","r",stdin);
    freopen("EULER4.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for (int i=1;i<=timer;i++) v[h[tour[i]]].push_back(i);
    while (m--) {
        int u,k;
        cin>>u>>k;
        int x=h[u]+k;
        cout<<upper_bound(v[x].begin(),v[x].end(),en[u])-lower_bound(v[x].begin(),v[x].end(),st[u])<<'\n';
    }
}
