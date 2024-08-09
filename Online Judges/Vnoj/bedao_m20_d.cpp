#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,val;
int a[N+5];
vector<vector<int>>adj(N+5);
bool vis[N+5];
int bfs(int lim) {
    if (lim<a[1]) return INT_MIN;
    queue<pair<int,int>>q;
    memset(vis,false,sizeof(vis));
    vis[1]=true;
    q.push({1,1});
    while (!q.empty()) {
        int u=q.front().first;
        int d=q.front().second;
        q.pop();
        if (u==n) return lim-d;
        for (auto v:adj[u]) {
            if (vis[v]) continue;
            if (a[v]>lim) continue;
            vis[v]=true;
            q.push({v,d+1});
        }
    }
    return INT_MIN;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (bfs(n)==INT_MIN) {
        cout<<-1;
        return 0;
    }
    int lo=0,hi=n;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        int temp=bfs(mid);
        if (temp<=0) {
            lo=mid+1;
            val=temp;
        } else hi=mid-1;
    }
    if (lo<=n) {
        int temp=bfs(lo);
        if (val==INT_MIN) cout<<temp;
        else cout<<min(abs(val),temp);

    } else cout<<abs(val);
}
