#include<bits/stdc++.h>
using namespace std;
const int M=1e7,N=1e5;
struct Node{
	int left,right;
	int val;
	Node(){}
	Node(int val,int left,int right):val(val),left(left),right(right){}
} st[M+5];
int nnode,nver,n,q,k;
int ver[N+5],p[N+5],pos[N+5],mx[N+5];
int update(int l,int r,int u,int x,int oldid) {
	if (l==r) {
		++nnode;
		st[nnode]=Node(x,0,0);
		return nnode;
	}
	int mid=(l+r)/2;
	int cur=++nnode;
	if (u<=mid) {
		st[cur].left=update(l,mid,u,x,st[oldid].left);
		st[cur].right=st[oldid].right;
		st[cur].val=st[st[cur].left].val+st[st[cur].right].val;
	} else {
		st[cur].left=st[oldid].left;
		st[cur].right=update(mid+1,r,u,x,st[oldid].right);
		st[cur].val=st[st[cur].left].val+st[st[cur].right].val;
	}
	return cur;
}
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[id].val;
	int mid=(l+r)/2;
	return get(st[id].left,l,mid,u,v)+get(st[id].right,mid+1,r,u,v);
}
pair<int,int>query[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n>>q>>k;
	for (int i=1;i<=n;i++) {
		cin>>p[i];
		pos[p[i]]=i;
		mx[i]=max(mx[i-1],p[i]);
		++nver;
		ver[nver]=update(1,n,p[i],1,ver[nver-1]);
	}
	for (int i=1;i<=q;i++) cin>>query[i].first>>query[i].second;
	for (int i=q;i>=1;i--) {
		int l=query[i].first,r=query[i].second;
		if (k<l||k>r) continue;
		int lo=1,hi=mx[r-l+1],ans=0;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			//cout<<lo<<' '<<hi<<' '<<mid<<' '<<get(ver[r-l+1],1,n,1,mid)<<endl;
			int temp=get(ver[r-l+1],1,n,1,mid);
			if (temp==k-l+1) {
				ans=mid;
				hi=mid-1;
			} else if (temp>k-l+1) hi=mid-1;
			else lo=mid+1;
		}
		k=pos[ans]+l-1;
		//cout<<ans<<' '<<k<<endl;
	}
	cout<<k;
}
