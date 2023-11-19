#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
struct Node{
    long long lazy;
    long long val;
} st[4*N+5];
void down(int id,int l,int r) {
    long long t=st[id].lazy;
    int mid=(l+r)/2;
    st[id*2].lazy+=t;
    st[id*2].val+=t*(mid-l+1);
    st[id*2+1].lazy+=t;
    st[id*2+1].val+=t*(r-mid);
    st[id].lazy=0;
}
void build (int id,int l,int r) {
    if (l==r) {
        st[id].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
void update (int id,int l,int r,int u,int v,long long val) {
    if (l>v||r<u) return;
    if (u<=l&&r<=v) {
        st[id].lazy+=val;
        st[id].val+=(r-l+1)*val;
        return;
    }
    int mid=(l+r)/2;
    down(id,l,r);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
long long get (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 0;
    if (l>=u&&r<=v) return st[id].val;
    int mid=(l+r)/2;
    down(id,l,r);
    long long get1=get(id*2,l,mid,u,v);
    long long get2=get(id*2+1,mid+1,r,u,v);
    return get1+get2;
}
int main() {
    freopen("QSUM2.INP","r",stdin);
    freopen("QSUM2.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--) {
        int t;
        cin>>t;
        if (t==1) {
            int l,r;
            long long v;
            cin>>l>>r>>v;
            update(1,1,n,l,r,v);
        } else {
            int l,r;
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<endl;
        }
    }
}
