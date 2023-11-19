#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
pair<long long,long long>p[N+5];
long long pre_mx[N+5],pre_mn[N+5],suf_mx[N+5],suf_mn[N+5];
long long inf=1e18,res=inf;
void test1(int r) { // both max and min in [r,n]
    int lo=0,hi=r-2,l=0;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mn[mid]>=suf_mn[r]&&pre_mx[mid]<=suf_mx[r]) {
            lo=mid+1;
            l=mid;
        } else hi=mid-1;
    }
    res=min(res,suf_mx[r]-suf_mn[r]+p[r-1].first-p[l+1].first);
}
struct Seg1{
    long long st[N*4+5];
    void build (int id,int l,int r) {
        if (l==r) {
            st[id]=-pre_mn[l]-p[l+1].first;
            return;
        }
        int mid=(l+r)/2;
        build (id*2,l,mid);
        build (id*2+1,mid+1,r);
        st[id]=min(st[id*2],st[id*2+1]);
    }
    long long get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return inf;
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} st1;
void test2(int r) { //only max in [r,n]
    int lo=0,hi=r-2,p1=-1,p2=-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mx[mid]<=suf_mx[r]){
            lo=mid+1;
            p1=mid;
        } else hi=mid-1;
    }
    lo=0,hi=r-2;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mn[mid]<suf_mn[r]) {
            p2=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    if (p1==-1||p2==-1||p1<p2) return;
    res=min(res,st1.get(1,1,n,p2,p1)+suf_mx[r]+p[r-1].first);
}
struct Seg2{
    long long st[N*4+5];
    void build (int id,int l,int r) {
        if (l==r) {
            st[id]=pre_mx[l]-p[l+1].first;
            return;
        }
        int mid=(l+r)/2;
        build (id*2,l,mid);
        build (id*2+1,mid+1,r);
        st[id]=min(st[id*2],st[id*2+1]);
    }
    long long get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return inf;
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} st2;
void test3(int r) { //only min in [r,n]
    int lo=0,hi=r-2,p1=-1,p2=-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mn[mid]>=suf_mn[r]) {
            lo=mid+1;
            p1=mid;
        } else hi=mid-1;
    }
    lo=0,hi=r-2;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mx[mid]>suf_mx[r]) {
            p2=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    if (p1==-1||p2==-1||p1<p2) return;
    res=min(res,st2.get(1,1,n,p2,p1)+p[r-1].first-suf_mn[r]);
}
struct Seg3{
    long long st[N*4+5];
    void build (int id,int l,int r) {
        if (l==r) {
            st[id]=pre_mx[l]-pre_mn[l]-p[l+1].first;
            return;
        }
        int mid=(l+r)/2;
        build (id*2,l,mid);
        build (id*2+1,mid+1,r);
        st[id]=min(st[id*2],st[id*2+1]);
    }
    long long get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return inf;
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
} st3;
void test4(int r) { //no min max in [r,n]
    int lo=0,hi=r-2,p1=-1,p2=-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mn[mid]<suf_mn[r]) {
            p2=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    lo=0,hi=r-2;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (pre_mx[mid]>suf_mx[r]) {
            p1=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    if (p1==-1||p2==-1) return;
    res=min(res,st3.get(1,1,n,max(p1,p2),r-2)+p[r-1].first);
}
int main() {
    //freopen("toy.inp","r",stdin);
    //freopen("toy.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    sort(p+1,p+1+n);
    pre_mn[0]=suf_mn[n+1]=INT_MAX;
    for (int i=1;i<=n;i++) {
        pre_mx[i]=max(pre_mx[i-1],p[i].second);
        pre_mn[i]=min(pre_mn[i-1],p[i].second);
    }
    for (int i=n;i>=1;i--) {
        suf_mx[i]=max(suf_mx[i+1],p[i].second);
        suf_mn[i]=min(suf_mn[i+1],p[i].second);
    }
    st1.build(1,1,n);
    st2.build(1,1,n);
    st3.build(1,1,n);
    for (int r=n;r>1;r--) {
        test1(r);
        test2(r);
        test3(r);
        test4(r);
    }
    for (int r=n;r>1;r--) {
        long long s1=p[n].first-p[r].first;
        long long s2=pre_mx[r-1]-pre_mn[r-1];
        res=min(res,s1+s2);
    }
    cout<<res;
}
/*
4
4 5
1 9
5 3
2 10
2
*/
