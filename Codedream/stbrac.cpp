#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const int inf=1e9;
int n,a[N+3],st1[N*4+3],m,st2[N*4+3],lazy[N*4+3],sum[N+3];
string s;
void down(int id, int l, int r){
    if(!lazy[id]) return;
    st2[id]+=lazy[id];
    if(l!=r){
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
    }
    lazy[id]=0;
}
void build1(int id, int l, int r){
    if(l==r){
        st1[id]=a[l];
        return;
    }
    int m=(l+r)/2;
    build1(id*2,l,m);
    build1(id*2+1,m+1,r);
    st1[id]=st1[id*2]+st1[id*2+1];
}
void build2(int id, int l, int r){
    if(l==r){
        st2[id]=sum[l];
        return;
    }
    int m=(l+r)/2;
    build2(id*2,l,m);
    build2(id*2+1,m+1,r);
    st2[id]=min(st2[id*2],st2[id*2+1]);
}
void upd1(int id, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;
    if(l==r){
        st1[id]+=val;
        return;
    }
    int m=(l+r)/2;
    upd1(id*2,l,m,pos,val);
    upd1(id*2+1,m+1,r,pos,val);
    st1[id]=st1[id*2]+st1[id*2+1];
}
void upd2(int id, int l, int r, int u, int v, int val){
    down(id,l,r);
    if(l>v || r<u) return;
    if(l==r){
        lazy[id]+=val;
        down(id,l,r);
        return;
    }
    int m=(l+r)/2;
    upd2(id*2,l,m,u,v,val);
    upd2(id*2+1,m+1,r,u,v,val);
    st2[id]=min(st2[id*2],st2[id*2+1]);
}
int get1(int id, int l, int r, int u, int v){
    if(l>=u && r<=v) return st1[id];
    if(l>v || r<u) return 0;
    int m=(l+r)/2;
    return get1(id*2,l,m,u,v)+get1(id*2+1,m+1,r,u,v);
}
int get2(int id, int l, int r, int u, int v){
    down(id,l,r);
    if(l>=u && r<=v) return st2[id];
    if(l>v || r<u) return inf;
    int m=(l+r)/2;
    return min(get2(id*2,l,m,u,v),get2(id*2+1,m+1,r,u,v));
}
int main(){
    freopen("STBRAC.INP","r",stdin);
	freopen("STBRAC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        if(s[i]=='(') a[i]=1;
        else a[i]=-1;
        sum[i]=sum[i-1]+a[i];
    }
    build1(1,1,n);
    build2(1,1,n);
    while(m--){
        int t; cin>>t;
        if(t==0){
            int i; char c; cin>>i>>c;
            if(a[i]==1 && c=='(') continue;
            else if(a[i]==-1 && c==')') continue;
            else if(a[i]==-1 && c=='('){
                upd1(1,1,n,i,2);
                upd2(1,1,n,i,n,2);
                a[i]=-a[i];
            }
            else if(a[i]==1 && c==')'){
                upd1(1,1,n,i,-2);
                upd2(1,1,n,i,n,-2);
                a[i]=-a[i];
            }
        }else{
            int i,j; cin>>i>>j;
            if(get1(1,1,n,1,i-1)==get1(1,1,n,1,j) && get1(1,1,n,1,i-1)<=get2(1,1,n,i,j)) cout<<1;
            else cout<<0;
        }
    }
}
