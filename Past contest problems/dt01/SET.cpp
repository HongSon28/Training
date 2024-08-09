#include<bits/stdc++.h>
using namespace std;
int a,b,k;
bool vis[1000][1000];
bool bfs(int x,int y) {
    memset(vis,false,sizeof(vis));
    queue<pair<int,int>>q;
    q.push({x,y});
    while (!q.empty()) {
        pair<int,int>p=q.front();
        vis[p.first][p.second]=true;
        q.pop();
        if (p.first>a&&p.second>b&&!vis[p.first-1][p.second-1]) q.push({p.first-1,p.second-1});
        if (p.first<a&&p.second<b&&!vis[p.first*k][p.second*k]) q.push({p.first*k,p.second*k});
        if (p.first==a&&p.second<=b&&!vis[p.second][b]) {
            q.push({p.second,b});
            if (p.first-1>=0&&p.second-1>=0&&!vis[p.first-1][p.second-1])q.push({p.first-1,p.second-1});
            if (p.first*k<1000&&p.second*k<1000&&!vis[p.first*k][p.second*k])q.push({p.first*k,p.second*k});
        }
        if (p.second==b&&p.first<=a&&!vis[p.first][a]) {
            q.push({p.first,a});
            if (p.first-1>=0&&p.second-1>=0&&!vis[p.first-1][p.second-1])q.push({p.first-1,p.second-1});
            if (p.first*k<1000&&p.second*k<1000&&!vis[p.first*k][p.second*k])q.push({p.first*k,p.second*k});
        }
        if (p.second==a&&p.first<=b&&!vis[p.first][b]) {
            q.push({p.first,b});
            if (p.first-1>=0&&p.second-1>=0&&!vis[p.first-1][p.second-1])q.push({p.first-1,p.second-1});
            if (p.first*k<1000&&p.second*k<1000&&!vis[p.first*k][p.second*k])q.push({p.first*k,p.second*k});
        }
        if (p.first==b&&p.second<=a&&!vis[p.second][a]) {
            q.push({p.second,a});
            if (p.first-1>=0&&p.second-1>=0&&!vis[p.first-1][p.second-1])q.push({p.first-1,p.second-1});
            if (p.first*k<1000&&p.second*k<1000&&!vis[p.first*k][p.second*k])q.push({p.first*k,p.second*k});
        }
        if (p.first==a&&p.second==b) return true;
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        cin>>k>>a>>b;
        int m;
        cin>>m;
        while (m--) {
            int p,q;
            cin>>p>>q;
            if (!bfs(p,q)) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}
