#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
long long st[N*4+5];
void build (int id,int l,int r) {
    if (l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void update (int id,int l,int r,int i,long long val) {
    if (l>i||r<i) return;
    if (l==r) {
        st[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,i,val);
    update(id*2+1,mid+1,r,i,val);
    st[id]=st[id*2]+st[id*2+1];
}
long long get (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 0;
    if (l>=u&&r<=v) return st[id];
    int mid=(l+r)/2;
    long long get1=get(id*2,l,mid,u,v);
    long long get2=get(id*2+1,mid+1,r,u,v);
    return get1+get2;
}
int main() {
    cin>>n;
    build(1,1,n);
    cin>>q;
    while (q--) {
        int t,x,y;
        cin>>t>>x>>y;
        if (t==1) update(1,1,n,x,y);
        else cout<<get(1,1,n,x,y)<<endl;
    }
}
