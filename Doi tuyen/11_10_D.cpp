#include<bits/stdc++.h>
using namespace std;
const int N=1e5,LG=__lg(N);
int n,m,s,t;
vector<vector<int>>adj(N+5);
int up[N+5][LG+5],rmq[N+5][LG+5],h[N+5];
int trace[N+5];
queue<int>q1,q2;
bool vis[N+5];
void bfs() {
    q1.push(s);
    q2.push(s);
    vis[s]=true;
    while (!q1.empty()) {
        int u=q1.front();
        q1.pop();
        for (auto v:adj[u]) {
            if (vis[v]) continue;
            h[v]=h[u]+1;
            vis[v]=true;
            q1.push(v);
            q2.push(v);
            if (v==t) return;
        }
    }
}
bool better(int u,int v) {
    int mn1=INT_MAX,mn2=INT_MAX;
    for (int i=LG;i>=0;i--) {
        if (up[u][i]!=up[v][i]) {
            mn1=min(mn1,rmq[u][i]);
            mn2=min(mn2,rmq[v][i]);
            u=up[u][i];
            v=up[v][i];
        }
    }
    mn1=min(mn1,u);
    mn2=min(mn2,v);
    return mn1<mn2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    if (!vis[t]) {
        cout<<-1;
        return 0;
    }
    while (!q2.empty()) {
        int u=q2.front();
        q2.pop();
        for (auto v:adj[u]) {
            if (h[v]==h[u]-1) {
                //cout<<u<<' '<<v<<' '<<h[v]<<' '<<trace[u]<<endl;
                if (trace[u]==0||better(v,trace[u])) trace[u]=v;
            }
        }
        rmq[u][0]=u;
        up[u][0]=trace[u];
        for (int j=1;j<=LG;j++) {
            up[u][j]=up[up[u][j-1]][j-1];
            rmq[u][j]=min(rmq[u][j-1],rmq[up[u][j-1]][j-1]);
        }
    }
    vector<int>tr;
    while(t!=s) {
        tr.push_back(t);
        t=trace[t];
    }
    cout<<s<<' ';
    for (int i=tr.size()-1;i>=0;i--) cout<<tr[i]<<' ';
}
