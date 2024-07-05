#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
string s;
int l=1e6,r=l+1;
struct node{
	int val,lazy;
} st[N*4+5];
void down(int id,int l,int r) {
	int mid=(l+r)/2;
	if (st[id].lazy==0) {
		st[id*2].lazy=0;
		st[id*2+1].lazy=0;
		st[id*2].val=0;
		st[id*2+1].val=0;
	} else if (st[id].lazy==1) {
		st[id*2].lazy=1;
		st[id*2+1].lazy=1;
		st[id*2].val=mid-l+1;
		st[id*2+1].val=r-mid;
	}
	st[id].lazy=-1;
}
void update(int id,int l,int r,int u,int v,int val) {
	if (v<l||u>r) return;
	if (u<=l&&r<=v) {
		st[id].val=val*(r-l+1);
		st[id].lazy=val;
		return;
	}
	int mid=(l+r)/2;
	down(id,l,r);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id].val=st[id*2].val+st[id*2+1].val;
}
int get(int id,int l,int r,int u,int v) {
	if (v<l||u>r) return 0;
	if (u<=l&&r<=v) return st[id].val;
	down(id,l,r);
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int walkr(int id,int l,int r,int val) {
	if (l==r) return l;
	int mid=(l+r)/2;
	down(id,l,r);
	if (st[id*2].val>=val) return walkr(id*2,l,mid,val);
	return walkr(id*2+1,mid+1,r,val-st[id*2].val);
}
int walkl(int id,int l,int r,int val) {
	if (l==r) return l;
	int mid=(l+r)/2;
	down(id,l,r);
	if (st[id*2+1].val>=val) return walkl(id*2+1,mid+1,r,val);
	return walkl(id*2,l,mid,val-st[id*2+1].val);
}
int main() {
	cin>>n>>s;
	s=' '+s;
	for (int i=1;i<N*4+5;i++) st[i].lazy=-1;
	update(1,1,N,l,l,1);
	for (int i=1;i<=n;i++) {
		if (s[i]=='L') {
			if (i%2==1) {
				int j=walkr(1,1,N,1+get(1,1,N,1,l-1));
				if (l<=j-1) update(1,1,N,l,j-1,1);
				l--;
				update(1,1,N,l,l,1);
			} else {
				int j=walkr(1,1,N,get(1,1,N,1,l-1));
				if (l<=j-1) update(1,1,N,l,j-1,0);
				l--;
			}
		} else {
			if (i%2==1) {
				int j=walkl(1,1,N,1+get(1,1,N,r+1,N));
				if (j+1<=r) update(1,1,N,j+1,r,1);
				r++;
				update(1,1,N,r,r,1);
			} else {
				int j=walkl(1,1,N,get(1,1,N,r+1,N));
				if (j+1<=r) update(1,1,N,j+1,r,0);
				r++;
			}
		}
	}
	int k1=get(1,1,N,l,r),k2=r-l+1-k1;
	cout<<k1<<' '<<k2;
}