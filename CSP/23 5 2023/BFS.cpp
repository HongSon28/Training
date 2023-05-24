#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("BFS.INP","r",stdin);
    freopen("BFS.OUT","w",stdout);
    int n,m;
    cin>>n>>m;
    bool vis[n+5];
    int trace[n+5];
    memset(vis,false,sizeof(vis));
    vector<vector<int>>v(n+5);
    for (int i=1;i<=m;i++) {
        int u,t;
        cin>>u>>t;
        v[u].push_back(t);
    }
    queue<int>s;
    s.push(1);
    vis[1]=true;
    while (!s.empty()) {
        int t=s.front();
        s.pop();
        for (int i=0;i<v[t].size();i++) {
            if (!vis[v[t][i]]) {
                vis[v[t][i]]=true;
                s.push(v[t][i]);
                trace[v[t][i]]=t;
            }
        }
    }
    vector<int>res;
    for (int i=n;i!=1;i=trace[i]) {
        res.push_back(trace[i]);
    }
    reverse(res.begin(),res.end());
    for (int i=0;i<res.size();i++) cout<<res[i]<<' ';
    cout<<n;
}
