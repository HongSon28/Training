#include<bits/stdc++.h>
using namespace std;
int n,mx,node;
const int N=1e5;
vector<vector<int>>adj(N+5);
vector<int>path;
int trace[N+5];
bool vis[N+5];
void farthest(int s,int cnt) {
    vis[s]=true;
    if (mx<cnt) {
        mx=cnt;
        node=s;
    }
    for (auto i:adj[s]) {
        if (!vis[i]) {
            vis[i]=true;
            farthest(i,cnt+1);
        }
    }
}
int main() {
    freopen("CTREE.INP","r",stdin);
    freopen("CTREE.OUT","w",stdout);
    cin>>n;
    if (n==1) {
        cout<<1<<endl<<1;
        return 0;
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    farthest(1,0);
    int end_point1=node;

    mx=0,node=0;
    memset(vis,false,sizeof(vis));
    farthest(end_point1,0);
    int end_point2=node;

    queue<int>q;
    memset(vis,false,sizeof(vis));
    q.push(end_point1);
    vis[end_point1]=true;
    while (!q.empty()) {
        int t=q.front();
        q.pop();
        for (auto i:adj[t]) {
            if (!vis[i]) {
                vis[i]=true;
                trace[i]=t;
                q.push(i);
            }
        }
    }

    trace[end_point1]=-1;
    for (int i=end_point2;i!=-1;i=trace[i]) {
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    if (path.size()%2==1) {
        cout<<1<<endl<<path[path.size()/2];
    } else {
        cout<<2<<endl;
        if (path[path.size()/2-1]>path[path.size()/2]) swap(path[path.size()/2-1],path[path.size()/2]);
        cout<<path[path.size()/2-1]<<' '<<path[path.size()/2];
    }
}
