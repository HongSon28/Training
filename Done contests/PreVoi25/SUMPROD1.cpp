#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q,k;
long long a[N+5],mod=998244353;
void add(long long &x,long long y) {
    x+=y;
    if (x>=mod) x-=mod;
}
namespace sub12{
    const int M=5000;
    struct SegmentTree{
        long long st[M*4+5],lazy[M*4+5];
        void build(int id,int l,int r) {
            lazy[id]=0;
            if (l==r) {
                st[id]=a[l];
                return;
            }
            int mid=(l+r)/2;
            build(id*2,l,mid);
            build(id*2+1,mid+1,r);
            st[id]=st[id*2];
            add(st[id],st[id*2+1]);
        }
        void down(int id,int l1,int r1,int l2,int r2) {
            if (lazy[id]==0) return;
            long long t=lazy[id];
            lazy[id]=0;
            add(lazy[id*2],t);
            add(lazy[id*2+1],t);
            add(st[id*2],t*(r1-l1+1)%mod);
            add(st[id*2+1],t*(r2-l2+1)%mod);
        }
        void update(int id,int l,int r,int u,int v,long long val) {
            if (l>v||r<u) return;
            if (u<=l&&r<=v) {
                add(st[id],val*(r-l+1)%mod);
                add(lazy[id],val);
                return;
            }
            int mid=(l+r)/2;
            down(id,l,mid,mid+1,r);
            update(id*2,l,mid,u,v,val);
            update(id*2+1,mid+1,r,u,v,val);
            st[id]=st[id*2];
            add(st[id],st[id*2+1]);
        }
        long long get(int id,int l,int r,int u,int v) {
            if (l>v||r<u) return 0;
            if (u<=l&&r<=v) return st[id];
            int mid=(l+r)/2;
            down(id,l,mid,mid+1,r);
            long long ans=get(id*2,l,mid,u,v);
            add(ans,get(id*2+1,mid+1,r,u,v));
            return ans;
        }
    }tree;
    void solve() {
        tree.build(1,1,n);
        while (q--) {
            int type,l,r,x;
            cin>>type>>l>>r;
            if (type==1) {
                cin>>x;
                tree.update(1,1,n,l,r,x);
            } else {
                long long res=0;
                for (int i=l;i+k<=r;i++) {
                    add(res,tree.get(1,1,n,i,i)*tree.get(1,1,n,i+k,r)%mod);
                    //cout<<a[i]<<' '<<tree.get(1,1,n,i+k,r)<<endl;
                }
                cout<<res<<'\n';
            }
        }
    }
}
namespace sub3{
    struct SegmentTree{
        long long sum[N*4+5],p[N*4+5],lazy[N*4+5];
        void build(int id,int l,int r) {
            lazy[id]=0;
            if (l==r) {
                sum[id]=a[l];
                p[id]=(a[l]*a[l])%mod;
                return;
            }
            int mid=(l+r)/2;
            build(id*2,l,mid);
            build(id*2+1,mid+1,r);
            sum[id]=sum[id*2];
            add(sum[id],sum[id*2+1]);
            p[id]=p[id*2];
            add(p[id],p[id*2+1]);
        }
        void down(int id,int l1,int r1,int l2,int r2) {
            if (lazy[id]==0) return;
            long long t=lazy[id];
            lazy[id]=0;
            add(lazy[id*2],t);
            add(lazy[id*2+1],t);
            add(p[id*2],2*sum[id*2]*t%mod);
            add(p[id*2],t*t%mod*(r1-l1+1)%mod);
            add(sum[id*2],t*(r1-l1+1)%mod);
            add(p[id*2+1],2*sum[id*2+1]*t%mod);
            add(p[id*2+1],t*t%mod*(r2-l2+1)%mod);
            add(sum[id*2+1],t*(r2-l2+1)%mod);
        }
        void update(int id,int l,int r,int u,int v,long long val) {
            if (l>v||r<u) return;
            if (u<=l&&r<=v) {
                //cout<<l<<' '<<r<<' '<<p[id]<<endl;
                add(p[id],2*sum[id]*val%mod);
                add(p[id],val*val%mod*(r-l+1)%mod);
                //cout<<l<<' '<<r<<' '<<p[id]<<endl;
                add(sum[id],val*(r-l+1)%mod);
                add(lazy[id],val);
                return;
            }
            int mid=(l+r)/2;
            down(id,l,mid,mid+1,r);
            update(id*2,l,mid,u,v,val);
            update(id*2+1,mid+1,r,u,v,val);
            sum[id]=sum[id*2];
            add(sum[id],sum[id*2+1]);
            p[id]=p[id*2];
            add(p[id],p[id*2+1]);
        }
        long long get_sum(int id,int l,int r,int u,int v) {
            if (l>v||r<u) return 0;
            if (u<=l&&r<=v) return sum[id];
            int mid=(l+r)/2;
            down(id,l,mid,mid+1,r);
            long long ans=get_sum(id*2,l,mid,u,v);
            add(ans,get_sum(id*2+1,mid+1,r,u,v));
            return ans;
        }
        long long get_p(int id,int l,int r,int u,int v) {
            if (l>v||r<u) return 0;
            if (u<=l&&r<=v) return p[id];
            int mid=(l+r)/2;
            down(id,l,mid,mid+1,r);
            long long ans=get_p(id*2,l,mid,u,v);
            add(ans,get_p(id*2+1,mid+1,r,u,v));
            return ans;
        }
    }tree;
    void solve() {
        tree.build(1,1,n);
        while (q--) {
            int type,l,r,x;
            cin>>type>>l>>r;
            if (type==1) {
                cin>>x;
                tree.update(1,1,n,l,r,x);
            } else {
                long long res=0;
                long long t=tree.get_sum(1,1,n,l,r);
                t=(t*t)%mod;
                add(res,t);
                res-=tree.get_p(1,1,n,l,r);
                if (res<0) res+=mod;
                res*=499122177;
                res%=mod;
                cout<<res<<'\n';
            }
        }
    }
}
int main() {
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sub12::solve();
}
/*
5 5 1
1 2 3 4 5
2 1 4
2 2 5
1 2 4 2
2 1 4
2 2 5
*/

