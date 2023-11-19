#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,w;
int t;
int st[N*4+5];
int inf=1e9;
int lo,hi,mid,ans;
void build(int id,int l,int r) {
    if (l==r) {
        st[id]=w;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int pos,int val) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]-=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
    if (r<u||l>v) return -inf;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    int get1=get(id*2,l,mid,u,v);
    int get2=get(id*2+1,mid+1,r,u,v);
    return max(get1,get2);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>w>>n;
    m=min(m,n);
    build(1,1,m);
    for (int i=1;i<=n;i++) {
        cin>>t;
        if (t>w) {
            cout<<-1<<'\n';
            continue;
        }
        lo=1,hi=m,ans=-1;
        while (lo<=hi) {
            mid=(lo+hi)/2;
            if (get(1,1,m,1,mid)>=t) {
                ans=mid;
                hi=mid-1;
            } else lo=mid+1;
        }
        if (ans!=-1) update(1,1,m,ans,t);
        cout<<ans<<'\n';
    }
}
