#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
vector<vector<int>>adj(N+5);
int h[N+5],res,inf=1e9;
void dfs(int u,int par) {
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u);
        h[u]=max(h[u],h[v]+1);
    }
}
void solve(int u,int par,int up,int mx) {
    vector<pair<int,int>>v1;
    for (auto v:adj[u]) {
        if(v==par) continue;
        v1.push_back({h[v],v});
    }
    sort(v1.rbegin(),v1.rend());
    if (v1.size()>=1) res=max(res,v1[0].first+1+max(mx+1,0));
    if (v1.size()>=2) res=max(res,v1[0].first+v1[1].first+2+max(mx+1,0));
    if (v1.size()>=3) res=max(res,v1[0].first+v1[1].first+v1[2].first+3);
    vector<pair<int,int>>v2;
    v2.push_back({up,-1});
    v2.push_back({-1,0});
    v2.push_back({-1,0});
    for (int i=0;i<min(3,(int)v1.size());i++) v2.push_back(v1[i]);
    sort(v2.rbegin(),v2.rend());
    for (auto v:adj[u]) {
        if (v==par) continue;
        if (v==v2[0].second) solve(v,u,v2[1].first+1,max(mx,v2[1].first+v2[2].first+2));
        else if (v==v2[1].second) solve(v,u,v2[0].first+1,max(mx,v2[0].first+v2[2].first+2));
        else solve(v,u,v2[0].first+1,max(mx,v2[0].first+v2[1].first+2));
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    solve(1,0,-1,-inf);
    cout<<res;
}
