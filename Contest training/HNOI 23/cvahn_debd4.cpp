#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
struct dat{
    long long s,t,c;
};
dat a[N+5];
long long dp[N+5];
long long inf=1e16;
long long res=inf;
bool comp(dat x,dat y) {
    if (x.s==y.s){
        if (x.t==y.t) {
            return x.c<y.c;
        }
        return x.t<y.t;
    }
    return x.s<y.s;
}
long long st[N*4+5];
void update(int id,long long l,long long r,long long pos,long long val) {
    //cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<val<<endl;
    if (r<pos||l>pos) return;
    if (l==r) {
        st[id]=min(st[id],val);
        return;
    }
    long long mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
long long get(int id,long long l,long long r,long long u,long long v) {
    //cout<<id<<' '<<l<<' '<<r<<' '<<u<<' '<<v<<' '<<st[id]<<endl;
    if (r<u||l>v) return inf;
    if (u<=l&&r<=v) return st[id];
    long long mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i].s>>a[i].t>>a[i].c;
    sort(a+1,a+1+m,comp);
    for (int i=1;i<=N;i++) dp[i]=inf;
    for (int i=1;i<=N*4;i++) st[i]=inf;
    update(1,0,N,0,0);
    for (int i=1;i<=m;i++) {
        long long temp=get(1,0,N,a[i].s,a[i].t-1);
        //cout<<a[i].s<<' '<<a[i].t<<' '<<a[i].c<<' '<<temp<<endl;
        dp[a[i].t]=min(dp[a[i].t],temp+a[i].c);
        //cout<<1<<' '<<0<<' '<<N<<' '<<a[i].s<<' '<<a[i].t<<' '<<dp[a[i].t]<<endl<<endl;
        update(1,0,N,a[i].t,dp[a[i].t]);
    }
    cout<<get(1,0,N,n,N);
}

