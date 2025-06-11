#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
long long a[N+5];
struct Node{
	long long pre,suf,sum,mx;
} st[N*4+5];
long long inf=1e18;
Node merge(Node x, Node y) {
	Node ans;
	ans.sum=x.sum+y.sum;
	ans.pre=max(x.pre,x.sum+y.pre);
	ans.suf=max(y.suf,y.sum+x.suf);
	ans.sum=x.sum+y.sum;
	ans.mx=max(x.mx,y.mx);
	ans.mx=max(ans.mx,x.suf+y.pre);
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id].sum=a[l];
		st[id].pre=st[id].suf=st[id].mx=max(0ll,a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int pos,long long val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].sum=val;
		st[id].pre=st[id].suf=st[id].mx=max(0ll,val);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=merge(st[id*2],st[id*2+1]);
	//cout<<id<<' '<<l<<' '<<r<<' '<<pos<<' '<<val<<' '<<st[id].pre<<' '<<st[id].suf<<' '<<st[id].sum<<' '<<st[id].mx<<endl;
}
Node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) {
		return {0,0,0,-inf};
	}
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (m--) {
    	int pos,val;
    	cin>>pos>>val;
    	update(1,1,n,pos,val);
    	cout<<get(1,1,n,1,n).mx<<'\n';
    }
}