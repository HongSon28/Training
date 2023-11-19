#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,a,b,res=-1;
int t[N+5];
vector<vector<int>>adj(N+5);
bool vis[N+5];
queue<int>q;
bool check(int mx) {
    while (!q.empty()) q.pop();
    memset(vis,false,sizeof(vis));
    q.push(a);
    vis[a]=true;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        if (u==b) return true;
        for (auto v:adj[u]) {
            if (vis[v]) continue;
            if (abs(t[v]-t[u])>mx) continue;
            q.push(v);
            vis[v]=true;
        }
    }
    return false;
}
int main() {
    cin>>n>>a>>b;
    for (int i=1;i<=n;i++) cin>>t[i];
    int u,v;
    while (cin>>u>>v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int lo=0,hi=2e4;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}
