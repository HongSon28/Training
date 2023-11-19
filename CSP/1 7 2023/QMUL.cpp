#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
long long st[N*4+5];
long long mod=70579053;
void build (int id,int l,int r) {
    if (l==r) {
        st[id]=a[l];
        st[id]%=mod;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]*st[id*2+1]%mod;
}
long long get (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 1;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    long long get1=get(id*2,l,mid,u,v)%mod;
    long long get2=get(id*2+1,mid+1,r,u,v)%mod;
    return get1*get2%mod;
}
int main() {
    freopen("QMUL.INP","r",stdin);
    freopen("QMUL.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--) {
        int l,r;
        cin>>l>>r;
        cout<<get(1,1,n,l,r)<<endl;
    }
}
