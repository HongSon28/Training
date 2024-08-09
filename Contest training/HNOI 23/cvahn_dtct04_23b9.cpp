#include<bits/stdc++.h>
using namespace std;
const int N=6e3;
int r[N+5];
vector<vector<int>>adj(N+5);
int n,res;
int a[N+5];
void lis(int n) {
    vector<int>b(n+1,INT_MAX);
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        res=max(res,k);
    }
    b[0]=INT_MIN;
    for (int i=1;i<=n;i++) b[i]=INT_MAX;
    for (int i=n;i>=1;i--) {
        int k=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        b[k]=a[i];
        res=max(res,k);
    }
}
void dfs(int u,int par,int h) {
    a[h]=r[u];
    if (adj[u].size()==1&&par!=0) {
        lis(h);
        return;
    }
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs(v,u,h+1);
    }
}
void dfs1(int u,int par) {
    if (adj[u].size()==1&&par!=0) {
        dfs(u,0,1);
        return;
    }
    for (auto v:adj[u]) {
        if (v==par) continue;
        dfs1(v,u);
    }
}
int main() {
    freopen("THAMHIEM.INP","r",stdin);
    freopen("THAMHIEM.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>r[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    cout<<res;
}
/*
6
1 2 3 4 5 1
1 2
2 3
3 4
3 5
3 6
*/
