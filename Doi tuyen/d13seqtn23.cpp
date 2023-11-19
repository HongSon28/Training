#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long st[4*N+5];
int n,q;
int f[N+5];
long long a[N+5];
void build(int id,int l,int r) {
    if (l==r) {
        st[id]=a[l]+a[f[l]];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void update(int id,int l,int r,int pos) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]=a[l]+a[f[l]];
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    st[id]=st[id*2]+st[id*2+1];
}
long long get(int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i+=2) {
        int j=i;
        while (j<=n) {
            f[j]=i;
            j*=2;
        }
    }
    build(1,1,n);
    while (q--) {
        int type;
        cin>>type;
        if (type==1) {
            long long i,c;
            cin>>i>>c;
            a[i]=c;
            if (i%2==0) continue;
            while (i<=n) {
                update(1,1,n,i);
                i*=2;
            }
        } else {
            int l,r;
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }
}
