#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
vector<vector<int>>adj(N+5);
vector<pair<int,int>>edge;
int h[N+5],par[N+5],res;
pair<int,int> mx[N+5][4];
void srt(int x) {
    if (mx[x][1].first<mx[x][2].first) swap(mx[x][1],mx[x][2]);
    if (mx[x][1].first<mx[x][3].first) swap(mx[x][1],mx[x][3]);
    if (mx[x][2].first<mx[x][3].first) swap(mx[x][2],mx[x][3]);
}
void dfs(int u) {
    for (auto v:adj[u]) {
        if (v==par[u]) continue;
        h[v]=h[u]+1;
        par[v]=u;
        dfs(v);
        if (mx[v][1].first+1>mx[u][3].first) {
            mx[u][3].first=mx[v][1].first+1;
            mx[u][3].second=v;
            srt(u);
        }
    }
}
void dfs2(int u) {
    if (par[u]!=0) {
        if (h[u]>mx[u][3].first) {
            mx[u][3].first=h[u];
            mx[u][3].second=par[u];
        }
        if (mx[par[u]][1].first+1>mx[u][3].first&&mx[par[u]][1].second!=u) {
            mx[u][3].first=mx[par[u]][1].first+1;
            mx[u][3].second=par[u];
        }
        if (mx[par[u]][2].first+1>mx[u][3].first&&mx[par[u]][2].second!=u) {
            mx[u][3].first=mx[par[u]][2].first+1;
            mx[u][3].second=par[u];
        }
        if (mx[par[u]][3].first+1>mx[u][3].first&&mx[par[u]][3].second!=u) {
            mx[u][3].first=mx[par[u]][3].first+1;
            mx[u][3].second=par[u];
        }
    }
    for (auto v:adj[u]) {
        if (v==par[u]) continue;
        dfs2(v);
    }
}
int main() {
    //freopen("buildpath.inp","r",stdin);
    //freopen("buildpath.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge.push_back({u,v});
    }
    dfs(1);
    dfs2(1);
    for (auto p:edge) {
        int u=p.first,v=p.second;
        vector<pair<int,int>>t1={mx[u][1],mx[u][2],mx[u][3]};
        vector<pair<int,int>>t2={mx[v][1],mx[v][2],mx[v][3]};
        sort(t1.begin(),t1.end());
        sort(t2.begin(),t2.end());
        int mx1=0,mx2=0,mx3=0,mx4=0;
        if (t1.back().second==v) t1.pop_back();
        mx1=t1.back().first;
        t1.pop_back();
        if (t1.back().second==v) t1.pop_back();
        mx2=t1.back().first;
        if (t2.back().second==u) t2.pop_back();
        mx3=t2.back().first;
        t2.pop_back();
        if (t2.back().second==u) t2.pop_back();
        mx4=t2.back().first;
        res=max(res,mx1+mx2+mx3+mx4+1);
        //cout<<u<<' '<<v<<' '<<mx1<<' '<<mx2<<' '<<mx3<<' '<<mx4<<' '<<mx1+mx2+mx3+mx4+1<<endl;
    }
    cout<<res;
}
