#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        bool flag=false;
        int n,m;
        cin>>n>>m;
        vector<vector<int>>adj(n+5);
        int vis[n+5]={};
        for (int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        vis[1]=1;
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for (auto v:adj[u]) {
                if (!vis[v]) {
                    if (vis[u]==1) vis[v]=2;
                    else vis[v]=1;
                    q.push(v);
                } else if (vis[u]==vis[v]) {
                    flag=true;
                    break;
                }
            }
        }
        if (flag) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
