#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
struct rec{
    int u,v,d,c;
};
rec a[N+5];
bool vis[N+5];
int area,res,n;
map<pair<int,int>,vector<int>>mp;
void dfs(int u) {
    vis[u]=true;
    area+=a[u].d*a[u].c;
    int x1=a[u].u,y1=a[u].v,x2=x1+a[u].d,y2=y1+a[u].c;
    for (int x=x1;x<=x2;x++) {
        for (auto v:mp[make_pair(x,y1)]) if (!vis[v]) dfs(v);
        for (auto v:mp[make_pair(x,y2)]) if (!vis[v]) dfs(v);
    }
    for (int y=y1;y<=y2;y++) {
        for (auto v:mp[make_pair(x1,y)]) if (!vis[v]) dfs(v);
        for (auto v:mp[make_pair(x2,y)]) if (!vis[v]) dfs(v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i].u>>a[i].v>>a[i].d>>a[i].c;
        mp[make_pair(a[i].u,a[i].v)].push_back(i);
        mp[make_pair(a[i].u+a[i].d,a[i].v)].push_back(i);
        mp[make_pair(a[i].u,a[i].v+a[i].c)].push_back(i);
        mp[make_pair(a[i].u+a[i].d,a[i].v+a[i].c)].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;
        area=0;
        dfs(i);
        res=max(res,area);
    }
    cout<<res;
}
