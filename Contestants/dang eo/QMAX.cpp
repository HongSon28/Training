#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int inf=1e18;
int n,q;
int a[N];
struct node{
    int val, lazy;
};
node st[4*N];
void down(int id){
    int t=st[id].lazy;
    st[id*2].lazy += t;
    st[id*2].val += t;
    st[id*2+1].lazy += t;
    st[id*2+1].val += t;
    st[id].lazy = 0;
}
void build(int id, int l,int r){
    if(l==r) {
        st[id].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].val=max(st[id*2].val, st[id*2+1].val);
}
void upd(int id, int l, int r, int u, int v, int val){
    if (v<l||u>r) return;
    if (u <= l && r <= v) {
        st[id].val += val;
        st[id].lazy += val;
        return ;
    }
    int mid=(l+r)/2;
    down(id);
    upd(id*2,l,mid,u,v,val);
    upd(id*2+1,mid+1,r,u,v,val);
    st[id].val=max(st[id*2].val, st[id*2+1].val);
}
int get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return -inf;
    if(l>=u && r<=v) return st[id].val;
    int mid=(l+r)/2;
    down(id);
    int get1=get(id*2,l,mid,u,v);
    int get2=get(id*2+1,mid+1,r,u,v);
    return max(get1, get2);
}
signed main(){
    freopen("QMAX.INP","r",stdin);
    freopen("QMAX.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int t,l,r,v;
        cin>>t;
        if(t==1){
            cin>>l>>r>>v;
            upd(1,1,n,l,r,v);
        }
        else{
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
}

