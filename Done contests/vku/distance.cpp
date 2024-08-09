#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<pair<int,int>>>adj(500001);
set<int>cafe;
struct td{
    int p,cnt;
};
int bfs(int m) {
    int res=INT_MAX;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    vis[m]=true;
    queue<td>q;
    for (auto i:adj[m]) {
        q.push({i.first,i.second});
        vis[i.first]=true;
    }
    while (!q.empty()) {
        td temp=q.front();
        q.pop();
        if (cafe.count(temp.p)!=0) res=min(res,temp.cnt);
        for (auto i:adj[temp.p]) {
            if (vis[i.first]==false) {
                vis[i.first]=true;
                q.push({i.first,temp.cnt+i.second});
            }
        }
    }
    return res;
}
int main() {
    cin>>n>>k;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    for (int i=0;i<k;i++) {
        int temp;
        cin>>temp;
        cafe.insert(temp);
    }
    for (int i=1;i<=n;i++) {
        cout<<bfs(i)<<' ';
    }
}
