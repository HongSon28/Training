#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=INT_MAX;
int n,q;
int a[N];
struct node{
    int val,pos;
};
node st[4*N];
void build(int id, int l, int r){
    if(l==r){
        st[id].pos=l;
        st[id].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
    if(st[id].val==st[id*2].val) st[id].pos=st[id*2].pos;
    else st[id].pos=st[id*2+1].pos;
}
node get(int id, int l, int r, int u, int v){
    if(l>v || r<u) return {inf,0};
    if(l>=u && r<=v) return st[id];
    int mid=(l+r)/2;
    node res;
    node getl=get(id*2,l,mid,u,v), getr=get(id*2+1,mid+1,r,u,v);
    res.val=max(getl.val,getr.val);
    if(res.val==getl.val) res.pos=getl.pos;
    else res.pos=getr.pos;
    return res;
}
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(q--){
        int l,r;
        cin>>l>>r;
        int mx2;
        node mx1=get(1,1,n,l,r);
        if(mx1.pos==l) mx2=get(1,1,n,mx1.pos+1,r).val;
        else if (mx1.pos==r) mx2=get(1,1,n,l,mx1.pos-1).val;
        else mx2=max(get(1,1,n,l,mx1.pos-1).val,get(1,1,n,mx1.pos+1,r).val);
        long long x=mx1.val+mx2;
        cout<<x<<'\n';
    }
}
/*
5 2
5 2 3 1 3
1 5
4 5
*/
