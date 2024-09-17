#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
struct Node {
	int mx,suf,pre,sum,pos,lazy;
} st[N*4+5];
Node merge(Node x,Node y,int lx,int rx,int ly,int ry) {
	Node ans;
	ans.pre=x.pre;
	if (x.sum==rx-lx+1) ans.pre=max(ans.pre,x.sum+y.pre);
	ans.suf=y.suf;
	if (y.sum==ry-ly+1) ans.suf=max(ans.suf,y.sum+x.suf);
	ans.sum=x.sum+y.sum;
	ans.lazy=-1;
	ans.mx=x.mx;
	ans.pos=x.pos;
	if (ans.mx<x.suf+y.pre) {
		ans.mx=x.suf+y.pre;
		ans.pos=rx-x.suf+1;
	} else if (ans.mx==x.suf+y.pre) ans.pos=min(ans.pos,rx-x.suf+1);
	if (ans.mx<y.mx) {
		ans.mx=y.mx;
		ans.pos=y.pos;
	} else if (ans.mx==y.mx) ans.pos=min(ans.pos,y.pos);
	return ans;
}
void down(int id,int l,int r) {
	if (st[id].lazy==-1) return;
	st[id*2].lazy=st[id*2+1].lazy=st[id].lazy;
	int mid=(l+r)/2;
	if (st[id].lazy==0) {
		st[id*2].pre=st[id*2].suf=st[id*2].sum=st[id*2].mx=0;
		st[id*2].pos=l;
		st[id*2+1].pre=st[id*2+1].suf=st[id*2+1].sum=st[id*2+1].mx=0;
		st[id*2+1].pos=mid+1;
	} else {
		st[id*2].pre=st[id*2].suf=st[id*2].sum=st[id*2].mx=mid-l+1;
		st[id*2].pos=l;
		st[id*2+1].pre=st[id*2+1].suf=st[id*2+1].sum=st[id*2+1].mx=r-mid;
		st[id*2+1].pos=mid+1;
	}
	st[id].lazy=-1;
}
void build(int id,int l,int r) {
	st[id].lazy=-1;
	st[id].pos=l;
	if (l==r) {
		st[id].mx=st[id].pre=st[id].suf=st[id].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1],l,mid,mid+1,r);
}
void update(int id,int l,int r,int u,int v,int val) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		if (!val) st[id].pre=st[id].suf=st[id].sum=st[id].mx=0;
		else st[id].pre=st[id].suf=st[id].sum=st[id].mx=r-l+1;
		st[id].pos=l;
		st[id].lazy=val;
		return;
	}
	int mid=(l+r)/2;
	down(id,l,r);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id]=merge(st[id*2],st[id*2+1],l,mid,mid+1,r);
}
int inf=1e9,res;
int get(int id,int l,int r,int k) {
	//cout<<id<<' '<<l<<' '<<r<<' '<<st[id].mx<<endl;
	if (st[id].mx<k) return inf;
	down(id,l,r); 
	int mid=(l+r)/2;
	if (st[id].pre>=k) return l;
	if (st[id*2].mx>=k) return get(id*2,l,mid,k);
	if (st[id*2].suf+st[id*2+1].pre>=k) return mid-st[id*2].suf+1;
	return get(id*2+1,mid+1,r,k);
}
int main() {
	//freopen("seating.in","r",stdin);
	//freopen("seating.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    build(1,1,n);
    while (m--) {
    	char type;
    	cin>>type;
    	if (type=='A') {
    		int k;
    		cin>>k;
    		int t=get(1,1,n,k);
    		//cout<<t<<endl;
    		if (t==inf) res++;
    		else update(1,1,n,t,t+k-1,0);
    	} else {
    		int l,r;
    		cin>>l>>r;
    		update(1,1,n,l,r,1);
    	}
    }
    cout<<res;
}