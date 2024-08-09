#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
int st[N*4+5];
int inf=1e9+5;
int lo,hi,res;
void build(int id,int l,int r) {
    if (l==r) {
        st[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
    if (u<=l&&r<=v) return st[id];
    if (l>v||r<u) return inf;
    int mid=(l+r)/2;
    int get1=get(id*2,l,mid,u,v);
    int get2=get(id*2+1,mid+1,r,u,v);
    return min(get1,get2);
}
bool check(int m) {
    for (int l=1;l<=n-m+1;l++) {
        int r=l+m-1;
        int temp=get(1,1,n,l,r);
        if (temp>=1-l) return true;
    }
    return false;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]-=i;
    }
    build(1,1,n);
    lo=1,hi=n;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            lo=mid+1;
            res=mid;
        } else hi=mid-1;
    }
    cout<<res;
}
