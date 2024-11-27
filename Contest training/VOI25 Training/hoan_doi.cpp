#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int p[N+5],pos[N+5];
long long a[N+5],sum[N+5];
struct SegmentTree{
	long long lazy[N*4+5],st[N*4+5],inf=1e18;
	void build(int id,int l,int r) {
		lazy[id]=0;
		if (l==r) {
			st[id]=sum[l];
			return;
		}
		int mid=(l+r)/2;
		build(id*2,l,mid);
		build(id*2+1,mid+1,r);
		st[id]=min(st[id*2],st[id*2+1]);
	}
	void down(int id) {
		if (lazy[id]==0) return;
		long long t=lazy[id];
		lazy[id]=0;
		lazy[id*2]+=t,st[id*2]+=t;
		lazy[id*2+1]+=t,st[id*2+1]+=t;
	}
	void update(int id,int l,int r,int u,int v,long long val) {
		if (l>v||r<u||u>v) return;
		if (u<=l&&r<=v) {
			st[id]+=val;
			lazy[id]+=val;
			return;
		}
		down(id);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id]=min(st[id*2],st[id*2+1]);
	}
} ST;
long long res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i];
    	pos[p[i]]=i;
    }	
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    }
    ST.build(1,1,n-1);
    res=ST.st[1];
    for (int x=1;x<=n;x++) {
    	int t=pos[x];
    	ST.update(1,1,n-1,1,t-1,a[t]);
    	ST.update(1,1,n-1,t,n-1,-a[t]);
    	//cout<<x<<' '<<t<<' '<<a[t]<<' '<<ST.st[1]<<endl;
    	res=min(res,ST.st[1]);
    }
    cout<<res;
}