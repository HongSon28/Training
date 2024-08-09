#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
long long st[N*4+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=st[id*2]+st[id*2+1];
}
void update(int id,int l,int r,int pos,long long val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=st[id*2]+st[id*2+1];
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (q--) {
    	int k,u,v;
    	cin>>k>>u>>v;
    	if (k==0) {
    		update(1,1,n,u,a[v]);
    		update(1,1,n,v,a[u]);
    		swap(a[u],a[v]);
    	} else cout<<get(1,1,n,u,v)<<'\n';	
    }
}