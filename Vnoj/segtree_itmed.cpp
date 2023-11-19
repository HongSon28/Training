#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long a[N+5],dp[N+5],st[N*4+5],inf=1e18;
void update(int id,int l,int r,int pos,long long val) {
    if (l>pos||r<pos) return;
    if (l==r) {
        st[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
long long get(int id,int l,int r,int u,int v) {
    if (l>v||r<u) return -inf;
    if (u<=l&&r<=v)return st[id];
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        dp[i]=max(0ll,a[i]);
        update(1,1,n,i,dp[i]);
    }
    for (int i=2;i<=n;i++) {
        long long temp=get(1,1,n,max(i-k,1),i-1);
        dp[i]=max(dp[i],temp+a[i]);
        update(1,1,n,i,dp[i]);
    }
    cout<<*max_element(dp+1,dp+1+n);;
}
