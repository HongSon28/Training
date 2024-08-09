#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long st[N*4+5],inf=1e18;
void update(int id,int l,int r,int pos,long long val) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
long long get(int id,int l,int r,int u,int v) {
    if (u>r||v<l) return inf;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    while (m--) {
        int type;
        cin>>type;
        if (type==1) {
            long long i,c;
            cin>>i>>c;
            update(1,1,n,i,c);
        } else {
            int l,r;
            cin>>l>>r;
            if (l<=r) cout<<get(1,1,n,l,r)<<'\n';
            else cout<<min(get(1,1,n,l,n),get(1,1,n,1,r))<<'\n';
        }
    }
}
