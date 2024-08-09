#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const int N=1e5;
int n,cnt,q;
int par[N+5];
long long res;
long long mn[N+5],id[N+5];
int findroot(int u) {
    if (par[u]<0) return u;
    return par[u]=findroot(par[u]);
}
void Union(int u,int v) {
    if (par[v]<par[u]) swap(u,v);
    par[u]+=par[v];
    par[v]=u;
}
struct Segment{
    long long y1,y2,val;
};
vector<Segment>seg[N+5];
struct node{
    pair<long long,long long>p1,p2;
    long long lazy;
};
node mer (node x,node y) {
    node ans;
    ans.p1.first=LLONG_MAX;
    if (x.p1.second!=0&&x.p1.first<ans.p1.first) ans.p1=x.p1;
    if (x.p2.second!=0&&x.p2.first<ans.p1.first) ans.p1=x.p2;
    if (y.p1.second!=0&&y.p1.first<ans.p1.first) ans.p1=y.p1;
    if (y.p2.second!=0&&y.p2.first<ans.p1.first) ans.p1=y.p2;
    ans.p2.first=LLONG_MAX;
    ans.p2.second=0;
    int rt=findroot(ans.p1.second);
    int temp=findroot(x.p1.second);
    if (x.p1.second!=0&&rt!=temp)
        if (ans.p2.first>x.p1.first)
            ans.p2.first=x.p1.first,ans.p2.second=temp;
    temp=findroot(x.p2.second);
    if (x.p2.second!=0&&rt!=temp)
        if (ans.p2.first>x.p2.first)
            ans.p2.first=x.p2.first,ans.p2.second=temp;
    temp=findroot(y.p1.second);
    if (y.p1.second!=0&&rt!=temp)
        if (ans.p2.first>y.p1.first)
            ans.p2.first=y.p1.first,ans.p2.second=temp;
    temp=findroot(y.p2.second);
    if (y.p2.second!=0&&rt!=temp)
        if (ans.p2.first>y.p2.first)
            ans.p2.first=y.p2.first,ans.p2.second=temp;
    ans.lazy=0;
    return ans;
}
struct segtree{
    node st[N*4+5];
    void build(int id,int l,int r) {
        if (l==r) {
            st[id].p1.second=l;
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id]=mer(st[id*2],st[id*2+1]);
    }
    void down(int id) {
        long long t=st[id].lazy;
        st[id].lazy=0;
        st[id*2].lazy+=t;
        st[id*2+1].lazy+=t;
        st[id*2].p1.first+=t;
        st[id*2].p2.first+=t;
        st[id*2+1].p1.first+=t;
        st[id*2+1].p2.first+=t;
    }
    void update(int id,int l,int r,int u,int v,long long val) {
        if (u>r||v<l) return;
        if (u<=l&&r<=v) {
            st[id].lazy+=val;
            st[id].p1.first+=val;
            st[id].p2.first+=val;
            return;
        }
        down(id);
        int mid=(l+r)/2;
        update(id*2,l,mid,u,v,val);
        update(id*2+1,mid+1,r,u,v,val);
        st[id]=mer(st[id*2],st[id*2+1]);
    }
}tree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(par,-1,sizeof(par));
    cin>>n>>q;
    cnt=n;
    while (q--) {
        long long u,v,x,y,w;
        cin>>u>>v>>x>>y>>w;
        seg[u].push_back({x,y,w});
        seg[v+1].push_back({x,y,-w});
        seg[x].push_back({u,v,w});
        seg[y+1].push_back({u,v,-w});
    }
    tree.build(1,1,n);
    while (cnt>1) {
        for (int i=1;i<=n;++i) {
            mn[i]=LLONG_MAX;
            id[i]=0;
        }
        for (int i=1;i<=n;++i) {
            for (auto s:seg[i]) tree.update(1,1,n,s.y1,s.y2,s.val);
            node temp=tree.st[1];
            int rt=findroot(i);
            if (temp.p1.second!=0&&findroot(temp.p1.second)!=rt) {
                if (temp.p1.first<mn[rt]) {
                    mn[rt]=temp.p1.first;
                    id[rt]=temp.p1.second;
                }
            } else if (temp.p2.second!=0&&findroot(temp.p2.second)!=rt) {
                if (temp.p2.first<mn[rt]) {
                    mn[rt]=temp.p2.first;
                    id[rt]=temp.p2.second;
                }
            }
        }
        for (int u=1;u<=n;++u) {
            int v=id[u];
            if (v==0) continue;
            int s=findroot(u),t=findroot(v);
            if (s!=t) {
                Union(s,t);
                res+=mn[u];
                cnt--;
            }
        }
        for (auto s:seg[n+1]) tree.update(1,1,n,s.y1,s.y2,s.val);
    }
    cout<<res;
}
