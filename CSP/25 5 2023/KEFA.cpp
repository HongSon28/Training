#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,res;
bool vis[N+5];
vector<vector<int>>adj(N+5);
int cat[N+5];
int main() {
    freopen("KEFA.INP","r",stdin);
    freopen("KEFA.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>cat[i];
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        if (u>v) swap(u,v);
        adj[u].push_back(v);
    }
    queue<pair<int,int>>q;
    q.push(make_pair(1,cat[1]));
    vis[1]=true;
    while (!q.empty()) {
        pair<int,int>t=q.front();
        q.pop();
        if (adj[t.first].size()==0&&t.second<=m) {
            res++;
           // cout<<t.first<<' ';
        }
        if (t.second<=m) {
            for (auto i:adj[t.first]) {
                if (!vis[i]) {
                    vis[i]=true;
                    if (cat[i]==0) q.push(make_pair(i,0));
                    else q.push(make_pair(i,t.second+1));
                }
            }
        }
    }
    cout<<res;
}
