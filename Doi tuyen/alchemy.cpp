#include<bits/stdc++.h>
using namespace std;
int n,cnt;
const int N=10000;
bool vis[N+5];
vector<vector<int>>adj(N+5);
map<string,int>mp;
int s,t;
void bfs() {
    queue<pair<int,int>>q;
    q.push({s,0});
    vis[s]=true;
    while (!q.empty()) {
        pair<int,int>p=q.front();
        q.pop();
        int u=p.first,w=p.second;
        if (u==t) {
            cout<<w;
            return;
        }
        for (auto v:adj[u]) {
            if (!vis[v]) {
                vis[v]=true;
                q.push({v,w+1});
            }
        }
    }
    cout<<-1;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        string u,t,v;
        cin>>u>>t>>v;
        if (mp[u]==0) {
            cnt++;
            mp[u]=cnt;
        }
        if (mp[v]==0) {
            cnt++;
            mp[v]=cnt;
        }
        adj[mp[u]].push_back(mp[v]);
    }
    string u,v;
    cin>>u>>v;
    if (mp[u]==0) {
        cnt++;
        mp[u]=cnt;
    }
    if (mp[v]==0) {
        cnt++;
        mp[v]=cnt;
    }
    s=mp[u],t=mp[v];
    bfs();
}
