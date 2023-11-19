#include<bits/stdc++.h>
using namespace std;
const int N=5e5,LG=__lg(N)+1;
int t,n,m;
struct edge{
    int u,v,l,r;
};
vector<edge>edges;
struct dat{
    int v,l,r;
};
vector<vector<dat>>adj(N+5);
int up[N+5][LG+5],mx[N+5][LG+5],mx2[N+5][LG+5];
int h[N+5];
void dfs(int u) {
    for (auto e:adj[u]) {
        int v=e.v;
        if (v==up[u][0]) continue;
        h[v]=h[u]+1;
        up[v][0]=u;
        mx[v][0]=e.l;
        mx2[v][0]=e.r;
        for (int k=1;k<=LG;k++) {
            up[v][k]=up[up[v][k-1]][k-1];
            mx[v][k]=max(mx[v][k-1],mx[up[v][k-1]][k-1]);
            mx2[v][k]=max(mx2[v][k-1],mx2[up[v][k-1]][k-1]);
        }
        dfs(v);
    }
}
int getmax(int u,int v){
    int ans=0;
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        int k=h[u]-h[v];
        for (int i=0;(1<<i)<=k;i++) {
            if (k>>i&1) {
                ans=max(ans,mx[u][i]);
                u=up[u][i];
            }
        }
    }
    if (u==v) return ans;
    int k=__lg(h[u]);
    for (int i=k;i>=0;i--) {
        if (up[u][i]!=up[v][i]) {
            ans=max(ans,mx[u][i]);
            ans=max(ans,mx[v][i]);
            u=up[u][i];
            v=up[v][i];
        }
    }
    ans=max(ans,mx[u][0]);
    ans=max(ans,mx[v][0]);
    return ans;
}
void update(int u,int v,int val) {
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        int k=h[u]-h[v];
        for (int i=0;(1<<i)<=k;i++) {
            if (k>>i&1) {
                mx2[u][i]=min(mx2[u][i],val);
                u=up[u][i];
            }
        }
    }
    if (u==v) return;
    int k=__lg(h[u]);
    for (int i=k;i>=0;i--) {
        if (up[u][i]!=up[v][i]) {
            mx2[u][i]=min(mx2[u][i],val);
            mx2[v][i]=min(mx2[v][i],val);
            u=up[u][i];
            v=up[v][i];
        }
    }
    mx2[u][0]=min(mx2[u][0],val);
    mx2[v][0]=min(mx2[v][0],val);
}
vector<pair<int,int>>seg[N+5];
set<pair<int,int>>st;
int res[N+5];
void solve() {
    for (int i=0;i<n-1;i++) {
        adj[edges[i].u].push_back({edges[i].v,edges[i].l,edges[i].r});
        adj[edges[i].v].push_back({edges[i].u,edges[i].l,edges[i].r});
    }
    dfs(1);
    for (int i=n-1;i<edges.size();i++) {
        edges[i].l=max(edges[i].l,getmax(edges[i].u,edges[i].v)+1);
        update(edges[i].u,edges[i].v,edges[i].r-1);
    }
    for (int k=LG;k>=1;k--) {
        for (int i=1;i<=n;i++) {
            mx2[i][k-1]=min(mx2[i][k-1],mx2[i][k]);
            mx2[up[i][k-1]][k-1]=min(mx2[up[i][k-1]][k-1],mx2[i][k]);
        }
    }
    for (int i=0;i<n-1;i++) {
        int temp;
        if (h[edges[i].u]>h[edges[i].v]) temp=edges[i].u;
        else temp=edges[i].v;
        edges[i].r=mx2[temp][0];
    }
    for (int i=0;i<edges.size();i++) {
        seg[edges[i].l].push_back({edges[i].r,i});
    }
    for (int i=1;i<=m;i++) {
        for (auto p:seg[i]) st.insert(p);
        if (st.empty()) {
            cout<<"NO"<<'\n';
            return;
        }
        pair<int,int>temp=*st.begin();
        if (temp.first<i) {
            cout<<"NO"<<'\n';
            return;
        }
        st.erase(st.begin());
        res[temp.second+1]=i;
    }
    for (int i=1;i<=m;i++)
        if (res[i]==-1||res[i]>m) {
            cout<<"NO"<<'\n';
            return;
        }
    cout<<"YES"<<'\n';
    for (int i=1;i<=m;i++) cout<<res[i]<<' ';
    cout<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        edges.clear();
        cin>>n>>m;
        st.clear();
        adj.clear();
        adj.resize(n+1);
        for (int i=1;i<=m;i++) {
            seg[i].clear();
            res[i]=-1;
        }
        for (int i=1;i<=m;i++) {
            int u,v,l,r;
            cin>>u>>v>>l>>r;
            edges.push_back({u,v,l,r});
        }
        solve();
    }
}
