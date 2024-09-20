#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5],res;
struct Node {
	int sum,pre,suf;
} st[N*4+5];
Node merge(Node x,Node y) {
	Node ans;
	ans.sum=x.sum+y.sum;
	ans.pre=max(x.pre,x.sum+y.pre);
	ans.suf=max(y.suf,y.sum+x.suf);
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id]={a[l],max(0,a[l]),max(0,a[l])};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
Node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u||u>v) return {0,0,0};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int stmx[N*4+5];
void build_mx(int id,int l,int r) {
	if (l==r) {
		stmx[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build_mx(id*2,l,mid);
	build_mx(id*2+1,mid+1,r);
	stmx[id]=max(stmx[id*2],stmx[id*2+1]);
}
int getmx(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return -31;
	if (u<=l&&r<=v) return stmx[id];
	int mid=(l+r)/2;
	return max(getmx(id*2,l,mid,u,v),getmx(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    build_mx(1,1,n);
    for (int i=1;i<=n;i++) {
    	int lo=1,hi=i-1,l=i,r=i;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (getmx(1,1,n,mid,i-1)<=a[i]) {
    			l=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	lo=i+1,hi=n;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (getmx(1,1,n,i+1,mid)<=a[i]) {
    			r=mid;
    			lo=mid+1;
    		} else hi=mid-1;
    	}
    	res=max(res,get(1,1,n,l,i-1).suf+get(1,1,n,i+1,r).pre);
    }
    cout<<res;
}