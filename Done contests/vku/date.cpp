#include<bits/stdc++.h>
using namespace std;
long long res;
long long N=1e9+7;
vector<vector<long long>>v(100001);
vector<long long>a;
long long vis[100001],f[100001];
void dfs(int u) {
    vis[u]=1;
    for (int i=0;i<v[u].size();i++) {
        if (vis[v[u][i]]==0) dfs(v[u][i]);
    }
    a.push_back(u);
    vis[u]=2;
}
int main() {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    for (int i=1;i<=n;i++) {
        if (vis[i]==0) dfs(i);
    }
    //reverse(a.begin(),a.end());
    f[1]=1;
    for (auto u:a) {
        for (auto vv:v[u]) {
            f[u]+=f[vv];
            f[u]%=N;
        }
    }
    cout<<f[n];
}
