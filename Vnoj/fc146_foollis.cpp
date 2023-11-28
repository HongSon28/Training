#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
int a[N+5],st[N*4+5];
int inf=1e9;
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r){
		st[id]=max(st[id],val);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return -inf;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v)); 
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		int mx=get(1,0,N,max(0,a[i]-k),a[i]-1);
		update(1,0,N,a[i],mx+1);
	}
	cout<<st[1];
}