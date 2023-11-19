#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
pair<long long,long long> st[N*4+5];
long long inf=1e18;
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
long long getmin (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return inf;
    if (u<=l&&r<=v) return st[id].first;
    int mid=(l+r)/2;
    long long get1=getmin(id*2,l,mid,u,v);
    long long get2=getmin(id*2+1,mid+1,r,u,v);
    return min(get1,get2);
}
long long getmax (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return -inf;
    if (u<=l&&r<=v) return st[id].second;
    int mid=(l+r)/2;
    long long get1=getmax(id*2,l,mid,u,v);
    long long get2=getmax(id*2+1,mid+1,r,u,v);
    return max(get1,get2);
}
int main() {
    freopen("LINEUP.INP","r",stdin);
    freopen("LINEUP.OUT","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (q--) {
        int l,r;
        cin>>l>>r;
        cout<<getmax(1,1,n,l,r)-getmin(1,1,n,l,r)<<endl;
    }
}
