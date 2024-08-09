#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
struct node{
	int val,lazy;
}st[N*4+5];
node mer(node x,node y) {
	return {x.val+y.val,0};
}
void down(int id,int l,int r) {
	int t=st[id].lazy;
	st[id].lazy=0;
	if (t==0) return;
	int mid=(l+r)/2;
	st[id*2].lazy^=1;
	st[id*2].val=(mid-l+1)-st[id*2].val;
	st[id*2+1].lazy^=1;
	st[id*2+1].val=(r-mid)-st[id*2+1].val;
}
void update(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		st[id].val=(r-l+1)-st[id].val;
		st[id].lazy^=1;
		return;
	}
	int mid=(l+r)/2;
	down(id,l,r);
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id]=mer(st[id*2],st[id*2+1]);
}
node get(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return {0,0};
	if (l==r) return st[id];
	int mid=(l+r)/2;
	down(id,l,r);
	return mer(get(id*2,l,mid,pos),get(id*2+1,mid+1,r,pos));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	update(1,1,n,l,r);
    }
    for (int i=1;i<=n;i++) cout<<get(1,1,n,i).val<<' ';
}