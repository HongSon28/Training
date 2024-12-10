#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
long long x,y;
int a[N+5];
stack<int>st;
int l[N+5],r[N+5];
long long res[N+5];
struct SegmentTree{
	long long st[N*4+5],lazy[N*4+5];
	void reset() {
		memset(st,0,sizeof(st));
		memset(lazy,0,sizeof(lazy));
	}
	void down(int id,int l1,int r1,int l2,int r2) {
		if (!lazy[id]) return;
		long long t=lazy[id];
		lazy[id]=0;
		lazy[id*2]+=t,lazy[id*2+1]+=t;
		st[id*2]+=t*(r1-l1+1),st[id*2+1]+=t*(r2-l2+1);
	}
	void update(int id,int l,int r,int u,int v,long long val) {
		if (l>v||r<u||u>v) return;
		if (u<=l&&r<=v) {
			st[id]+=val*(r-l+1);
			lazy[id]+=val;
			return;
		}
		int mid=(l+r)/2;
		down(id,l,mid,mid+1,r);
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id]=st[id*2]+st[id*2+1];
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		down(id,l,mid,mid+1,r);
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
} tree;
vector<pair<int,int>>vl[N+5],vr[N+5],ql[N+5],qr[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q>>x>>y;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		while (!st.empty()&&a[i]>a[st.top()]) st.pop();
		if (!st.empty()) l[i]=st.top();
		else l[i]=0;
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i=n;i>=1;i--) {
		while (!st.empty()&&a[i]>a[st.top()]) st.pop();
		if (!st.empty()) r[i]=st.top();
		else r[i]=n+1;
		st.push(i);
	}
	for (int i=1;i<=n;i++) {
		vr[r[i]].push_back({l[i],i});
		vl[l[i]].push_back({r[i],i});
	}
	for (int i=1;i<=q;i++) {
		int l,r;
		cin>>l>>r;
		ql[l].push_back({r,i});
		qr[r].push_back({l,i});
	}
	for (int r=1;r<=n;r++) {
		if (r>1) tree.update(1,1,n,r-1,r-1,x);
		for (auto [l,i]:vr[r]) {
			tree.update(1,1,n,l,l,x);
			tree.update(1,1,n,l+1,i-1,y);
		}
		for (auto [l,id]:qr[r]) res[id]+=tree.get(1,1,n,l,r);
	}
	tree.reset();
	for (int l=n;l>=1;l--) {
		for (auto [r,i]:vl[l]) {
			tree.update(1,1,n,i+1,r-1,y);
		}
		for (auto [r,id]:ql[l]) res[id]+=tree.get(1,1,n,l,r);
	}
	for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}