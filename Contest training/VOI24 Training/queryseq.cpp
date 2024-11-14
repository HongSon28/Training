#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5;
struct query{
    int l,r,id;
    bool operator < (const query &other) const {
        return r<other.r;
    }
}q[N+5];
int n,m;
int a[N+5];
ll res[N+5];
ll last[N+5],nxt[N+5],pos[N+5];
struct Fenwick {
    ll bit[N+5];
    void update (int p,ll val) {
        for (int x=p;x<=N;x+=x&(-x)) bit[x]+=val;
    }
    ll get(int p) {
        ll ans=0;
        for (int x=p;x>0;x-=x&(-x)) ans+=bit[x];
        return ans;
    }
    ll Get(int l,int r) {
        return get(r)-get(l-1);
    }
}tree1, tree2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        last[i]=pos[a[i]];
        nxt[pos[a[i]]]=i;
        pos[a[i]]=i;
    }
    for (int i=1;i<=m;i++) {
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q+1,q+1+m);
    int j=1;
    for (int i=1;i<=m;i++) {
        while (j<=q[i].r) {
            tree1.update(j,-j);
            if (nxt[j]!=0) tree1.update(j,nxt[j]);
            if (last[j]!=0) tree2.update(last[j],j-last[j]);
            tree2.update(j,j-nxt[j]);
            j++;
        }
        res[q[i].id]=tree1.Get(q[i].l,q[i].r)+tree2.Get(q[i].l,q[i].r);
    }
    for (int i=1;i<=m;i++) cout<<res[i]<<'\n';
}
