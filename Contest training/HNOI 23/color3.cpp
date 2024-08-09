#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
string s;
vector<vector<int>>adj(N+5);
int color[N+5];
bool vis[N+5];
queue<int>q;
void bfs(int u) {
    vis[u]=true;
    q.push(u);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        bool one=false,two=false,three=false;
        if (s[u]=='R') one=true;
        else if (s[u]=='G') two=true;
        else three=true;
        for (auto v:adj[u]) {
            if (!vis[v]) {
                vis[v]=true;
                q.push(v);
            }
            if (color[v]==1) one=true;
            else if (color[v]==2) two=true;
            else if (color[v]==3) three=true;
        }
        if (!one) color[u]=1;
        else if (!two) color[u]=2;
        else if (!three) color[u]=3;
        else {
            cout<<"Impossible";
            exit(0);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) bfs(i);
    }
    for (int i=1;i<=n;i++) {
        if (color[i]==1) cout<<"R";
        else if (color[i]==2) cout<<"G";
        else cout<<"B";
    }
}

