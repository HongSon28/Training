#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
int a[N+5];
int st[N*4+5];
int inf=1e9+7;
void build (int id,int l,int r) {
    if (l==r) {
        st[id]=l;
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    if (a[st[id*2]]<a[st[id*2+1]]) st[id]=st[id*2];
    else st[id]=st[id*2+1];
}
void update (int id,int l,int r,int i,long long val) {
    if (l>i||r<i) return;
    if (l==r) {
        st[id]=i;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,i,val);
    update(id*2+1,mid+1,r,i,val);
    if (a[st[id*2]]<a[st[id*2+1]]) st[id]=st[id*2];
    else st[id]=st[id*2+1];
}
long long get (int id,int l,int r,int u,int v) {
    if (l>v||r<u) return n+1;
    if (u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    long long get1=get(id*2,l,mid,u,v);
    long long get2=get(id*2+1,mid+1,r,u,v);
    if (a[get1]<a[get2]) return get1;
    return get2;
}
void solve(int i,int u,int v) {
    int temp=a[i];
    a[i]=inf;
    update(1,1,n,i,inf);
    cout<<a[get(1,1,n,u,v)]<<endl;
    a[i]=temp;
    update(1,1,n,i,temp);

}
int main() {
    freopen("QMIN2.INP","r",stdin);
    freopen("QMIN2.OUT","w",stdout);
    cin>>n;
    a[n+1]=inf;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while (q--) {
        int x,y;
        cin>>x>>y;
        int temp=get(1,1,n,x,y);
        solve(temp,x,y);
    }
}
