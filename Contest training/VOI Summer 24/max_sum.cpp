#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,m;
int a[N+5];
struct node{
	int pre,suf,sum,mx;
} st[N*4+5];
int inf=1e9;
node merge(node x,node y) {
	node ans;
	ans.pre=max(x.pre,x.sum+y.pre);
	ans.suf=max(y.suf,y.sum+x.suf);
	ans.sum=x.sum+y.sum;
	ans.mx=max({x.mx,y.mx,x.suf+y.pre});
	return ans;
}
void build(int id,int l,int r) {
	if (l==r) {
		st[id]={a[l],a[l],a[l],a[l]};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=merge(st[id*2],st[id*2+1]);
}
node get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {-inf,-inf,0,-inf};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>m;
    while (m--) {
    	int x,y;
    	cin>>x>>y;
    	cout<<get(1,1,n,x,y).mx<<'\n';
    }
}