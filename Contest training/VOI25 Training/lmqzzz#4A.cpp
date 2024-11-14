#include<bits/stdc++.h>
using namespace std;
const int N=2e4,M=1e3;
int n,k;
pair<int,int>p[N+5];
vector<int>cprs;
vector<int>v1[N+5],v2[N+5];
int dp[N+5][M+5],res;	
struct SegmentTree{
	int st[N*4+5],lazy[N*4+5];
	void down(int id) {
		int t=lazy[id];
		if (t==0) return;
		lazy[id]=0;
		lazy[id*2]+=t,lazy[id*2+1]+=t;
		st[id*2]+=t;
		st[id*2+1]+=t;
	}
	void update(int id,int l,int r,int u,int v,int val) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id]+=val;
			lazy[id]+=val;
			return;
		}
		int mid=(l+r)/2;
		down(id);
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id]=max(st[id*2],st[id*2+1]);
	}
	int get() {
		return st[1];
	}
} tree[M+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	k=min(k,n);
	for (int i=1;i<=n;i++) {
		cin>>p[i].first>>p[i].second;
		cprs.push_back(p[i].first);
		cprs.push_back(p[i].second);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) {
		p[i].first=lower_bound(cprs.begin(),cprs.end(),p[i].first)-cprs.begin()+1;
		p[i].second=lower_bound(cprs.begin(),cprs.end(),p[i].second)-cprs.begin()+1;
		v1[p[i].first].push_back(p[i].second);
		v2[p[i].second].push_back(p[i].first);
	}
	int m=cprs.size();
	for (int i=1;i<=m;i++) {
		for (int t=0;t<=k;t++) {
			for (auto r:v1[i]) tree[t].update(1,0,m,0,i-1,1);
			for (auto l:v2[i-1]) tree[t].update(1,0,m,0,l-1,-1);
		}
		for (int t=1;t<=k;t++) {
			dp[i][t]=tree[t-1].get();
			tree[t].update(1,0,m,i,i,dp[i][t]);
			res=max(res,dp[i][t]);
		}
	}
	cout<<res;
}