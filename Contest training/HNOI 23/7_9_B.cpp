#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
struct Node {
    long long val,lazy;
};
Node st[N*4+5];
void down(int id,int l,int r) {
    int mid=(l+r)/2;
    long long t=st[id].lazy;
    st[id].lazy=0;
    st[id*2].lazy+=t;
    st[id*2].val+=t*(mid-l+1);
    st[id*2+1].lazy+=t;
    st[id*2+1].val+=t*(r-mid);
}
void update(int id,int l,int r,int u,int v,long long val) {
    if (l>v||r<u) return;
    if (l>=u&&r<=v) {
        st[id].val+=val*(r-l+1);
        st[id].lazy+=val;
        return;
    }
    down(id,l,r);
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
long long get(int id,int l,int r,int u,int v) {
    //cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<endl;
    if (r<u||l>v) return 0;
    if (l>=u&&r<=v) return st[id].val;
    int mid=(l+r)/2;
    down(id,l,r);
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
            long long l,r,d;
            cin>>l>>r>>d;
            update(1,1,n,l,r,d);
        } else {
            int x;
            cin>>x;
            cout<<get(1,1,n,x,x)<<'\n';
        }
    }
}

