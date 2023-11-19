#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
vector<vector<int>>adj(N+5);
long long a[N+5];
long long h[N+5],st[N+5],en[N+5],tour[N+5];
long long timer;
long long str[N*4+5];
void build(int id,int l,int r) {
    if (l==r) {
        str[id]=a[tour[l]];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    str[id]=str[id*2]+str[id*2+1];
}
void update(int id,int l,int r,int pos,long long val) {
    if (l>pos||r<pos) return;
    if (l==r&&r==pos) {
        str[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    str[id]=str[id*2]+str[id*2+1];
}
long long get(int id,int l,int r,int u,int v) {
    if (l>=u&&r<=v) return str[id];
    if (l>v||r<u) return 0;
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void dfs(int u,int par) {
    h[u]=h[par]+1;
    timer++;
    st[u]=timer;
    tour[timer]=u;
    for (auto v:adj[u]) {
        if (v!=par) {
            dfs(v,u);
        }
    }
    en[u]=timer;
}
int main() {
    freopen("EULER2.INP","r",stdin);
    freopen("EULER2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    build(1,st[1],en[1]);
    while (m--) {
        int type;
        cin>>type;
        if (type==1) {
            long long u,c;
            cin>>u>>c;
            update(1,st[1],en[1],st[u],c);
        } else {
            int u;
            cin>>u;
            cout<<get(1,st[1],en[1],st[u],en[u])<<'\n';
        }
    }
}
