#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long
using namespace std;
const int N=5e5;
ll inf=1e18;
int n,a[N+3];
ll w[N+3],st[N*4+3],res;
vector<int>vt;
void upd(int id, int l, int r, int pos, ll val){
    if(r<pos||l>pos) return;
    if(l==r){
        st[id]=max(st[id],val);
        return;
    }
    int mid=(l+r)/2;
    upd(id*2,l,mid,pos,val);
    upd(id*2+1,mid+1,r,pos,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
ll get(int id, int l, int r, int u, int v){
    if(r<u || l>v) return -inf;
    if(u<=l && r<=v) return st[id];
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>w[i];
        vt.push_back(a[i]);
    }
    sort(vt.begin(),vt.end());
    vt.resize(unique(vt.begin(),vt.end())-vt.begin());
    for(int i=1;i<=n;i++) a[i]=lower_bound(vt.begin(),vt.end(),a[i])-vt.begin()+1;
    for(int i=1;i<=n;i++){
        ll x=get(1,0,n,0,a[i]-1);
        upd(1,0,n,a[i],w[i]+x);
        res=max(res,w[i]+x);
    }
    cout<<res;
}