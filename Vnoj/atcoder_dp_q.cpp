#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
#define ll long long
ll n,h[N+5],a[N+5],dp[N+5],res;
struct node{
    ll val,lazy;
}st[N*4+5];
void down(int id) {
    ll t=st[id].lazy;
    st[id].lazy=0;
    st[id*2].lazy=max(st[id*2].lazy,t);
    st[id*2].val=max(st[id*2].val,t);
    st[id*2+1].lazy=max(st[id*2+1].lazy,t);
    st[id*2+1].val=max(st[id*2+1].val,t);
}
void update(int id,int l,int r,int u,int v,ll val) {
    if (l>v||r<u) return;
    if (u<=l&&r<=v) {
        st[id].val=max(st[id].val,val);
        st[id].lazy=max(st[id].lazy,val);
        return;
    }
    int mid=(l+r)/2;
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
ll get(int id,int l,int r,int u,int v) {
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v) return st[id].val;
    int mid=(l+r)/2;
    down(id);
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        ll temp=get(1,1,n,1,h[i]-1);
        dp[i]=temp+a[i];
        update(1,1,n,h[i],n,dp[i]);
        res=max(res,dp[i]);
        //cout<<temp<<' '<<h[i]<<' '<<dp[i]<<endl;
    }
    cout<<res;
}
