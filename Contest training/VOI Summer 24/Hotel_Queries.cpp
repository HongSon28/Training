#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N+5];
int st[N*4+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=max(st[id*2],st[id*2+1]);
}
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int k) {
	if (st[id]<k) return 0;
	if (l==r) return l;
	int mid=(l+r)/2;
	if (st[id*2]>=k) return get(id*2,l,mid,k);
	return get(id*2+1,mid+1,r,k);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (m--) {
    	int r;
    	cin>>r;
    	int t=get(1,1,n,r);
    	cout<<t<<' ';
    	if (t>0) update(1,1,n,t,-r);
    }
}