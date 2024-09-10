#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N+5];
struct SegmentTree{
	struct Node{
		int pre,suf,sum,mx;
	} st[N*4+5];
	int val;
	Node merge(Node x,Node y,int lx,int rx,int ly,int ry) {
		Node ans;
		ans.pre=x.pre;
		if (x.sum==rx-lx+1) ans.pre=max(ans.pre,x.sum+y.pre);
		ans.suf=y.suf;
		if (y.sum==ry-ly+1) ans.suf=max(ans.suf,y.sum+x.suf);
		ans.sum=x.sum+y.sum;
		ans.mx=max({x.mx,y.mx,x.suf+y.pre});
		return ans;
	}
	void build(int id,int l,int r) {
		if (l==r) {
			if (a[l]==val) st[id]={1,1,1,1};
			else st[id]={0,0,0,0};
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		st[id]=merge(st[id*2],st[id*2+1],l,mid,mid+1,r);
	}
	void update(int id,int l,int r,int pos) {
		if (l>pos||r<pos) return;
		if (l==r) {
			if (a[l]==val) st[id]={1,1,1,1};
			else st[id]={0,0,0,0};
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos);
		update(id*2+1,mid+1,r,pos);
		st[id]=merge(st[id*2],st[id*2+1],l,mid,mid+1,r);
	}
} tree[2];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    string s;
    cin>>s;
    n=s.size();
    for (int i=1;i<=n;i++) a[i]=(s[i-1]=='1');
    tree[0].val=0;
    tree[1].val=1;
    tree[0].build(1,1,n);
    tree[1].build(1,1,n);
    cin>>m;
    while (m--) {
    	int x;
    	cin>>x;
    	a[x]^=1;
    	tree[0].update(1,1,n,x);
    	tree[1].update(1,1,n,x);
    	cout<<max(tree[0].st[1].mx,tree[1].st[1].mx)<<' ';
    }
}