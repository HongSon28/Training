#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,q;
long long a[N+5];
long long sum[N+5];
long long inf=1e16;
struct node{
    int minsum, maxsum, ans;
    node() {minsum=inf,maxsum=-inf,ans=-inf;}
    node(int x,int y,int z) {minsum=x,maxsum=y,ans=z;}
};
node Merge (node a, node b) {
    node c;
    c.minsum=min(a.minsum,b.minsum);
    c.maxsum=max(a.maxsum,b.maxsum);
    c.ans=max({a.ans,b.ans,b.maxsum-a.minsum});
    return c;
}
node Nodes[N*4+5];
void build (int id,int l,int r) {
    if (l==r) {
        Nodes[id]=node(sum[l-1],sum[l],a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*id,l,mid);
    build(2*id+1,mid+1,r);
    Nodes[id]=Merge(Nodes[id*2],Nodes[id*2+1]);
}
node get(int id,int l,int r,int u,int v) {
    if (u>r||v<l) return node();
    if (u<=l&&r<=v) return Nodes[id];
    int mid=(l+r)/2;
    return Merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
    //freopen("QSUM.INP","r",stdin);
    //freopen("QSUM.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    build(1,1,n);
    cin>>q;
    while (q--) {
        int l,r;
        cin>>l>>r;
        node temp=get(1,1,n,l,r);
        cout<<temp.ans<<endl;
    }
}
