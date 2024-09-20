#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int d[N+5];
int n,m;
int a[N+5];
void seive() {
	for (int i=1;i<=N;i++) d[i]=i;
	for (int i=2;i*i<=N;i++) {
		if (d[i]==i)
			for (int j=i*i;j<=N;j+=i)
				if (d[j]>i) d[j]=i;
	}
}
int f(int x) {
	int ans=1;
	while (x>1) {
		int div=d[x];
		int cnt=0;
		while (x%div==0) {
			x/=div;
			cnt++;
		}
		ans*=cnt+1;
	}
	return ans;
}
struct SegmentTree{
	struct Node {
		long long mx,sum;
	} st[N*4+5];
	Node merge(Node x,Node y) {
		return {max(x.mx,y.mx),x.sum+y.sum};
	}
	void build(int id,int l,int r) {
		if (l==r) {
			st[id].mx=st[id].sum=a[l];
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		st[id]=merge(st[id*2],st[id*2+1]);
	}
	void update(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v&&st[id].mx<=2) return;
		if (l==r) {
			int t=f(st[id].sum);
			st[id]={t,t};
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v);
		update(id*2+1,mid+1,r,u,v);
		st[id]=merge(st[id*2],st[id*2+1]);
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return 0;
		if (u<=l&&r<=v) return st[id].sum;
		int mid=(l+r)/2;
		return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
	}
} st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    seive();
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    st.build(1,1,n);
    while (m--) {
    	int type,l,r;
    	cin>>type>>l>>r;
    	if (type==1) st.update(1,1,n,l,r);
    	else cout<<st.get(1,1,n,l,r)<<'\n';
    }
}