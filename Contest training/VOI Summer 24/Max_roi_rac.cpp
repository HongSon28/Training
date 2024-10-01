#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
int a[N+5];
int st[N*4+5],inf=1e9+1;
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
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return -inf;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for (int i=1;i<=n;i++) {
		int d;
		cin>>d;
		cout<<get(1,1,n,max(1,i-d),i)<<' ';
	}
}