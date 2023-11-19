#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,q;
int a[N+5];
pair<int,int> st[N*4+5];
int inf=1e9;
void build (int id,int l,int r) {
    if (l==r) {
        st[id].first=st[id].second=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].first=min(st[id*2].first,st[id*2+1].first);
    st[id].second=max(st[id*2].second,st[id*2+1].second);
}
void update (int id,int l,int r,int i,int val) {
    if (l>i||r<i) return;
    if (l==r) {
        st[id].first=st[id].second=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,i,val);
    update(id*2+1,mid+1,r,i,val);
    st[id].first=min(st[id*2].first,st[id*2+1].first);
    st[id].second=max(st[id*2].second,st[id*2+1].second);
}
pair<int,int> get (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return make_pair(inf,-inf);
    if (l>=u&&r<=v) return st[id];
    int mid=(l+r)/2;
    pair<int,int> get1=get(id*2,l,mid,u,v);
    pair<int,int> get2=get(id*2+1,mid+1,r,u,v);
    pair<int,int> res;
    res.first=min(get1.first,get2.first);
    res.second=max(get1.second,get2.second);
    return res;
}
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (q--) {
        int a,b;
        cin>>a>>b;
        pair<int,int>t=get(1,1,n,a,b);
        cout<<t.second-t.first<<endl;
    }
}
