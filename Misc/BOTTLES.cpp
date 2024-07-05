#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,k,f[N+5],a[N+5],st[N*4+5],res,t=1e9,s;
void upd(int id, int l, int r, int pos, int val){
    if(pos<l || pos>r) return;
    if(l==r){
        st[id]=val;
        return;
    }
    int m=(l+r)/2;
    upd(id*2,l,m,pos,val);
    upd(id*2+1,m+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id, int l, int r, int u, int v){
    if(v<l || u>r) return 1e9;
    if(l>=u && r<=v) return st[id];
    int m=(l+r)/2;
    int get1=get(id*2,l,m,u,v);
    int get2=get(id*2+1,m+1,r,u,v);
    return min(get1,get2);
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    for (int i=1;i<k;i++) {
    	f[i]=a[i];
    	upd(1,1,n,i,f[i]);
    }
    for(int i=k;i<=n;i++){
        int mn=get(1,1,n,i-k,i-1);
        f[i]=mn+a[i];
        upd(1,1,n,i,f[i]);
    }
    for(int i=n-k+1;i<=n;i++) t=min(t,f[i]);
    cout<<s-t;
}