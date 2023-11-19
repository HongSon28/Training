#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long st[N*4+5];
void update(int id,int l,int r,int pos,long long val) {
    if (l>pos||r<pos) return;
    if (l==pos&&r==pos) {
        st[id]+=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=st[id*2]+st[id*2+1];
}
long long get(int id,int l,int r,int u,int v) {
    //cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
    if (r<u||l>v) return 0;
    if (l>=u&&r<=v) return st[id];
    int mid=(l+r)/2;
    long long get1=get(id*2,l,mid,u,v);
    long long get2=get(id*2+1,mid+1,r,u,v);
    return get1+get2;
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
            long long x,d;
            cin>>x>>d;
            update(1,1,n,x,d);
        } else {
            int l,r;
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
}
