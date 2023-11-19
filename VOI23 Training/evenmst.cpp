#include<bits/stdc++.h>
using namespace std;
const int N=3e5,LG=__lg(N);
int n,m;
int par[N+5],cnt,cur;
int findroot(int x) {
    if (par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[y]<par[x]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
struct dat{
    int u,v,w;
};
dat edge[N+5];
bool used[N+5];
int up[N+5][LG+5];
int exist[2][N+5][LG+5];
int h[N+5];
vector<vector<pair<int,int>>>adj(N+5);
void dfs(int u,int par,int parid) {
    up[u][0]=par;
    for (int k=1;k<=LG;k++) up[u][k]=up[up[u][k-1]][k-1];
    if (parid) {
        int type=edge[parid].w%2;
        exist[type][u][0]=parid;
    }
    for (int k=1;k<=LG;k++) {
        exist[0][u][k]=max(exist[0][u][k-1],exist[0][up[u][k-1]][k-1]);
        exist[1][u][k]=max(exist[1][u][k-1],exist[1][up[u][k-1]][k-1]);
    }
    for (auto p:adj[u]) {
        int v=p.first,id=p.second;
        if (v==par) continue;
        h[v]=h[u]+1;
        dfs(v,u,id);
    }
}
int get(int type,int u,int v) {
    int ans=-1;
    if (h[u]!=h[v]) {
        if (h[u]<h[v]) swap(u,v);
        int k=h[u]-h[v];
        for (int i=0;(1<<i)<=k;i++) {
            if ((k>>i)&1) {
                ans=max(ans,exist[type][u][i]);
                u=up[u][i];
            }
        }
    }
    if (u==v) return ans;
    int k=__lg(h[u]);
    for (int i=k;i>=0;i--) {
        if (up[u][i]!=up[v][i]) {
            ans=max(ans,exist[type][u][i]);
            ans=max(ans,exist[type][v][i]);
            u=up[u][i];
            v=up[v][i];
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    memset(par,-1,sizeof(par));
    for (int i=1;i<=m;i++) {
        cin>>edge[i].u>>edge[i].v>>edge[i].w;
        edge[i].w%=2;
        if (findroot(edge[i].u)!=findroot(edge[i].v)) {
            Union(edge[i].u,edge[i].v);
            adj[edge[i].u].push_back({edge[i].v,i});
            adj[edge[i].v].push_back({edge[i].u,i});
            cnt++;
            cur+=edge[i].w;
            used[i]=true;
        }
    }
    if (cnt!=n-1) {
        cout<<"NO";
        return 0;
    }
    if (cur%2==0) {
        cout<<"YES"<<'\n';
        for (int i=1;i<=m;i++)
            if (used[i]) cout<<i<<' ';
        return 0;
    }
    memset(exist,-1,sizeof(exist));
    dfs(1,0,0);
    for (int i=1;i<=m;i++) {
        if (used[i]) continue;
        int temp=get(!(edge[i].w),edge[i].u,edge[i].v);
        if (temp==-1) continue;
        used[temp]=false;
        used[i]=true;
        cout<<"YES"<<'\n';
        for (int j=1;j<=m;j++)
            if (used[j]) cout<<j<<' ';
        return 0;
    }
    cout<<"NO";
}
