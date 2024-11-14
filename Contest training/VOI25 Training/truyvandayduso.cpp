#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
int a[N+5],res[N+5];
int nxt[N+5];
vector<int>pos[N+5];
int inf=1e9;
struct SegmentTree{
	struct Node {
		int val,lazy,mn;
	} st[N*4+5];
	void down(int id,int l,int r) {
		int t=st[id].lazy;
		st[id].lazy=0;
		if (t==0) return;
		int l1=l,r1=(l+r)/2,l2=r1+1,r2=r;
		st[id*2].val=st[id*2].lazy=t;
		st[id*2].mn=t-r1+1;
		st[id*2+1].val=st[id*2+1].lazy=t;
		st[id*2+1].mn=t-r2+1;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if (l>v||r<u||u>v) return;
		if (l>=u&&r<=v) {
			st[id].val=st[id].lazy=val;
			st[id].mn=val-r+1;
			return;
		}
		int mid=(l+r)/2;
		down(id,l,r);
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id].val=max(st[id*2].val,st[id*2+1].val);
		st[id].mn=min(st[id*2].mn,st[id*2+1].mn);
	}
	int get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (l>=u&&r<=v) return st[id].val;
		int mid=(l+r)/2;
		down(id,l,r);
		return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
	int getmin(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return inf;
		if (l>=u&&r<=v) return st[id].mn;
		int mid=(l+r)/2;
		down(id,l,r);
		return min(getmin(id*2,l,mid,u,v),getmin(id*2+1,mid+1,r,u,v));
	}
}tree;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	if (a[i]<n) pos[a[i]].push_back(i);
    }
    for (int i=0;i<n;i++) {
    	res[i]=inf;
    	int cur=1;
    	for (auto p:pos[i]) {
    		int ans=-1,lo=cur,hi=p;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (tree.get(1,1,n,cur,mid)<p) {
    				ans=mid;
    				lo=mid+1;
    			} else hi=mid-1;
    		}
    		if (ans!=-1) {
    			tree.update(1,1,n,cur,ans,p);
    		}
    		cur=p+1;
    	}
    	tree.update(1,1,n,cur,n,inf);
    	res[i]=tree.getmin(1,1,n,1,n);
    }
    while (q--) {
    	int x;
    	cin>>x;
    	if (x>=n||res[x]>n) cout<<-1<<'\n';
    	else cout<<res[x]<<'\n';
    }
}