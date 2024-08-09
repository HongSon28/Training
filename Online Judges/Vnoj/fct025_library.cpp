#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long a[N+5],res,cur;
int par[N+5];
vector<vector<int>>v(N+5);
int findroot(int u) {
    if (par[u]<0) return u;
    return u=findroot(par[u]);
}
void Union(int u,int v) {
    if ((u=findroot(u))==(v=findroot(v))) return;
    if (par[v]<par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    while (m--) {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    for (int i=1;i<=n;i++) v[findroot(i)].push_back(i);
    for (auto i:v) {
        if (i.empty()) continue;
        long long cur=LLONG_MAX;
        for (auto u:i) cur=min(cur,a[u]);
        res+=cur;
    }
    cout<<res;
}
