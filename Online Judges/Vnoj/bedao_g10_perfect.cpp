#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int p[N+5];
pair<int,int> st[N*4+5];
int inf=1e9;
void build (int id,int l,int r) {
    if (l==r) {
        st[id].first=st[id].second=p[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].first=min(st[id*2].first,st[id*2+1].first);
    st[id].second=max(st[id*2].second,st[id*2+1].second);
}
pair<int,int>get(int id,int l,int r,int u,int v) {
    if (u<=l&&r<=v) return st[id];
    if (v<l||r<u) return make_pair(inf,-inf);
    int mid=(l+r)/2;
    pair<int,int>get1=get(id*2,l,mid,u,v);
    pair<int,int>get2=get(id*2+1,mid+1,r,u,v);
    return make_pair(min(get1.first,get2.first),max(get1.second,get2.second));
}
int main() {
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>p[i];
    build(1,1,n);
    while (q--) {
        int l,r;
        cin>>l>>r;
        pair<int,int>t=get(1,1,n,l,r);
        if (t.second-t.first==r-l) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
