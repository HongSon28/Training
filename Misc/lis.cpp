#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
ll a[N+5];
ll n,mod=1e9+7;
vector<ll>nen;
struct node{
    ll len,d;
};
node st[4*N+5];
node mer(node a, node b){
    node c;
    if(a.len>b.len){
       c.len=a.len;
       c.d=a.d;
       c.d%=mod;
    }
    else if(a.len==b.len){
        c.d=a.d+b.d;
        c.len=a.len;
        c.d%=mod;
    }
    else{
        c.len=b.len;
        c.d=b.d;
        c.d%=mod;
    }
    return c;
}
void upd(ll id, ll l, ll r, ll pos, node val){
    if(l>pos||r<pos) return;
    if(l==r){
        if(val.len>st[id].len) st[id]=val;
        else if(val.len==st[id].len){
            st[id].d+=val.d;
            st[id].len=val.len;
        }
        return;
    }
    ll m=(l+r)/2;
    upd(id*2,l,m,pos,val);
    upd(id*2+1,m+1,r,pos,val);
    st[id]=mer(st[id*2],st[id*2+1]);
}
node get(ll id, ll l, ll r, ll u, ll v){
    if(l>v||r<u) return {0,0};
    if(u<=l&&r<=v) return st[id];
    ll m=(l+r)/2;
    node get1=get(id*2,l,m,u,v),get2=get(id*2+1,m+1,r,u,v);
    return mer(get1,get2);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        nen.push_back(a[i]);
    }
    sort(nen.begin(),nen.end());
    nen.resize(unique(nen.begin(),nen.end())-nen.begin());
    for(int i=1;i<=n;i++) a[i]=lower_bound(nen.begin(),nen.end(),a[i])-nen.begin()+1;
    for(int i=1;i<=n;i++){
        node temp=get(1,1,n,1,a[i]-1);
        ll mx=1,way=1;
        if(temp.len+1>mx) {
            mx=temp.len+1;
            way=temp.d;
        }
        cout<<a[i]<<' '<<mx<<' '<<way<<endl;
        upd(1,1,n,a[i],{mx,way});
    }
    cout<<st[1].d;
}
