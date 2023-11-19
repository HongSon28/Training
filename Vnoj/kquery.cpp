#include<bits/stdc++.h>
using namespace std;
const int N=3e4;
int n,q;
int a[N+5];
struct SegmentTree{
    vector<int>st[N*4+5],emp;
    void build(int id,int l,int r) {
        if (l==r) {
            st[id].push_back(a[l]);
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        vector<int>temp(st[id*2].size()+st[id*2+1].size());
        st[id]=temp;
        merge(st[id*2].begin(), st[id*2].end(), st[id*2+1].begin(), st[id*2+1].end(), st[id].begin());
    }
    int get(int id,int l,int r,int u,int v,int val) {
        if (l>v||r<u) return 0;
        if (u<=l&&r<=v) return st[id].size()-(upper_bound(st[id].begin(),st[id].end(),val)-st[id].begin());
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v,val)+get(id*2+1,mid+1,r,u,v,val);
    }
}Segtree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    Segtree.build(1,1,n);
    cin>>q;
    while(q--) {
        int i,j,k;
        cin>>i>>j>>k;
        cout<<Segtree.get(1,1,n,i,j,k)<<'\n';
    }
}
