#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5],b[N+5],d[N+5],cnt[N+5];
int pos[N+5];
int st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        d[b[i]]=i-pos[b[i]];
        if (d[b[i]]<=0) d[b[i]]+=n;
        update(1,1,n,d[b[i]],1);
    }
    while (q--) {
        int i,j;
        cin>>i>>j;
        update(1,1,n,d[b[i]],-1);
        d[b[i]]=j-pos[b[i]];
        if (d[b[i]]<=0) d[b[i]]+=n;
        update(1,1,n,d[b[i]],1);
        update(1,1,n,d[b[j]],-1);
        d[b[j]]=i-pos[b[j]];
        if (d[b[j]]<=0) d[b[j]]+=n;
        update(1,1,n,d[b[j]],1);
        swap(b[i],b[j]);
        cout<<st[1]<<'\n';
    }
}
