#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
int a[N+5];
vector<pair<int,int>>query[N+5];
int st[N*4+10];
void update(int id,int l,int r,int pos,int val) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int val) {
    if (l==r) return l;
    int mid=(l+r)/2;
    if (st[id*2]<val) return get(id*2,l,mid,val);
    return get(id*2+1,mid+1,r,val);
}
int res[N+5];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]=min(a[i],n+1);
    }
    for (int i=1;i<=q;i++) {
        int l,r;
        cin>>l>>r;
        query[r].push_back({l,i});
    }
    for (int i=1;i<=n;i++) {
        update(1,0,n+1,a[i],i);
        for (auto [l,id]:query[i]) {
            res[id]=get(1,0,n+1,l);
        }
    }
    for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}
