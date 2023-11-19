#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
long long base=71;
long long mod=1e9+7;
long long power[N+5];
string s;
int n,t;
void prep() {
    power[0]=1;
    for (int i=1;i<=n;i++) power[i]=(power[i-1]*base)%mod;
}
struct Node{
    long long hashh,sz;
    Node operator + (const Node &other) {
        return {((hashh*power[other.sz])%mod+other.hashh)%mod,sz+other.sz};
    }
};
struct segtree{
    Node st[N*4+5];
    void build(int id,int l,int r) {
        if (l==r) {
            st[id].hashh=(int)s[l]-'0';
            st[id].sz=1;
            return;
        }
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id]=st[id*2]+st[id*2+1];
    }
    void update(int id,int l,int r,int pos) {
        if (l>pos||r<pos) return;
        if (l==r) {
            st[id].hashh=0;
            st[id].sz=0;
            return;
        }
        int mid=(l+r)/2;
        update(id*2,l,mid,pos);
        update(id*2+1,mid+1,r,pos);
        st[id]=st[id*2]+st[id*2+1];
    }
    int getpos(int id,int l,int r,int pos) {
        if (l==r) return l;
        int mid=(l+r)/2;
        if (st[id*2].sz>=pos) return getpos(id*2,l,mid,pos);
        return getpos(id*2+1,mid+1,r,pos-st[id*2].sz);
    }
    Node get(int id,int l,int r,int u,int v) {
        if (l>v||r<u) return {0,0};
        if (u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
    }
}tree;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;
    prep();
    tree.build(1,1,n);
    cin>>t;
    while(t--) {
        char type;
        cin>>type;
        if (type=='-') {
            int i;
            cin>>i;
            i=tree.getpos(1,1,n,i);
            tree.update(1,1,n,i);
        } else {
            int l1,l2,x;
            cin>>l1>>l2>>x;
            int l=tree.getpos(1,1,n,l1),r=tree.getpos(1,1,n,l1+x-1);
            int u=tree.getpos(1,1,n,l2),v=tree.getpos(1,1,n,l2+x-1);
            Node t1=tree.get(1,1,n,l,r);
            Node t2=tree.get(1,1,n,u,v);
            if (t1.hashh==t2.hashh) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
