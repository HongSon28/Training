#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int res[N+5];
bool vis[N+5];
vector<vector<int>>adj(N+5);
int main() {
    freopen("BFS1.INP","r",stdin);
    freopen("BFS1.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<pair<int,int>>q;
    memset(res,-1,sizeof(res));
    q.push(make_pair(1,0));
    vis[1]=true;
    while (!q.empty()) {
        pair<int,int>t=q.front();
        q.pop();
        if (res[t.first]==-1) res[t.first]=t.second;
        for (auto i:adj[t.first]) {
            if (!vis[i]) {
                q.push(make_pair(i,t.second+1));
                vis[i]=true;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<endl;
}
