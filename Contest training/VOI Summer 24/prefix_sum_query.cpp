#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q;
long long a[N+5],sum[N+5];
long long inf=1e18;
struct node {
	long long val,lazy;
} st[N*4+5];
void down(int id) {
	long long t=st[id].lazy;
	st[id].lazy=0;
	st[id*2].lazy+=t;
	st[id*2].val+=t;
	st[id*2+1].lazy+=t;
	st[id*2+1].val+=t;
}
void build(int id,int l,int r) {
	st[id].lazy=0;
	if (l==r) {
		st[id].val=sum[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].val=max(st[id*2].val,st[id*2+1].val);
}
void update(int id,int l,int r,int u,int v,long long val) {
	if (l>v||r<u) return;
	if (u<=l&&r<=v) {
		st[id].val+=val;
		st[id].lazy+=val;
		return;
	}
	down(id);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id].val=max(st[id*2].val,st[id*2+1].val);
}
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return -inf;
	if (u<=l&&r<=v) return st[id].val;
	down(id);
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
long long bit[N+5];
void update_bit(int idx,long long val) {
	while (idx<=n) {
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}
long long get_bit(int idx) {
	long long ans=0;
	while (idx>0) {
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    	update_bit(i,a[i]);
    }
    build(1,1,n);
    while (q--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int k;
    		long long u;
    		cin>>k>>u;
    		update(1,1,n,k,n,u-a[k]);
    		update_bit(k,u-a[k]);
    		a[k]=u;
    	} else {
    		int a,b;
    		cin>>a>>b;
    		cout<<max(get(1,1,n,a,b)-get_bit(a-1),0ll)<<'\n';
    	}
    }
}