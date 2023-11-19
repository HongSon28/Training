#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q,cnt=0;
int st[N+5],en[N+5],par[N+5],c[N+5],leaf[N+5],pos[N+5],inf=1e9;
long long p[N+5];
vector<vector<int>>adj(N+5);
queue<int>qu;
void bfs() {
    qu.push(1);
    pos[1]=++cnt;
    c[1]=p[1];
    while (!qu.empty()) {
        int u=qu.front();
        qu.pop();
        int cur=0;
        for (auto v:adj[u]) {
            if (pos[v]) continue;
            par[v]=u;
            pos[v]=++cnt;
            c[cnt]=p[v];
            st[u]=min(st[u],pos[v]);
            en[u]=max(en[u],pos[v]);
            cur++;
            qu.push(v);
        }
        if (cur==0) leaf[u]=1;
    }
}
struct node{
    long long val,lazy;
};
node tree[N*4+5];
void down(int id,int l,int r) {
    int mid=(l+r)/2;
    long long temp=tree[id].lazy;
    tree[id].lazy=0;
    tree[id*2].lazy+=temp;
    tree[id*2+1].lazy+=temp;
    tree[id*2].val+=(mid-l+1)*temp;
    tree[id*2+1].val+=(r-mid)*temp;
}
void build (int id,int l,int r) {
    if (l==r) {
        tree[id].val=c[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    tree[id].val=tree[id*2].val+tree[id*2+1].val;
}
void update(int id,int l,int r,int u,int v,long long val) {
    if (l>v||r<u) return;
    if (u<=l&&r<=v) {
        tree[id].lazy+=val;
        tree[id].val+=(r-l+1)*val;
        return;
    }
    int mid=(l+r)/2;
    down(id,l,r);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    tree[id].val=tree[id*2].val+tree[id*2+1].val;
}
long long get(int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v) return tree[id].val;
    int mid=(l+r)/2;
    down(id,l,r);
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>p[i];
        st[i]=inf;
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    //for (int i=1;i<=n;i++) cout<<st[i]<<' '<<en[i]<<'\n';
    //return 0;
    build(1,1,n);
    while (q--) {
        int type;
        cin>>type;
        if (type==1) {
            int i,val;
            cin>>i>>val;
            if (!leaf[i]) update(1,1,n,st[i],en[i],val);
            update(1,1,n,pos[i],pos[i],2*val);
            if (par[i]!=0) update(1,1,n,pos[par[i]],pos[par[i]],val);
        } else {
            int i;
            long long res=0;
            cin>>i;
            if (!leaf[i]) res+=get(1,1,n,st[i],en[i]);
            res+=get(1,1,n,pos[i],pos[i]);
            if (par[i]!=0) res+=get(1,1,n,pos[par[i]],pos[par[i]]);
            cout<<res<<'\n';
        }
    }
}
