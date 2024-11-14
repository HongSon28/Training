#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
pair<long long,long long>p[N+5];
long long inf=1e18,res=-inf;
struct SegmentTree{
	long long st[N*4+5],lazy[N*4+5];
	void down(int id) {
		long long t=lazy[id];
		if (t==0) return;
		lazy[id]=0;
		lazy[id*2]+=t;
		st[id*2]+=t;
		lazy[id*2+1]+=t;
		st[id*2+1]+=t;
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
		st[id]=max(st[id*2],st[id*2+1]);
	}
	long long get(int id,int l,int r,int u,int v) {
		if (l>v||r<u||u>v) return -inf;
		if (u<=l&&r<=v) return st[id];
		down(id);
		int mid=(l+r)/2;
		return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
} tree;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>p[i].first>>p[i].second;
    	res=max(res,p[i].second);
    }
    sort(p+1,p+1+n);	
	for (int i=1;i<=n;i++) {
		tree.update(1,1,n,i,i,p[i].first+p[i].second);
		tree.update(1,1,n,1,i-1,p[i].second);
		res=max(res,-p[i].first+tree.get(1,1,n,1,i-1));
		//cout<<p[i].first<<' '<<p[i].second<<' '<<res<<endl;
	}
	cout<<res;
}