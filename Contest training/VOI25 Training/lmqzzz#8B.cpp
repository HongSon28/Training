#include<bits/stdc++.h>
using namespace std;
const int N=4e5;
int n;
int l[N+5],r[N+5];
vector<int>cprs;
int dp[N+5];
struct SegmentTree1{
	int st[N*4+5],inf=1e9+5;
	void build() {
		for (int i=1;i<=4*N;i++) st[i]=-inf;
	}
	void update(int id,int l,int r,int pos,int val) {
		if (l>pos||r<pos) return;
		if (l==r) {
			st[id]=max(st[id],val);
			return;
		}
		int mid=(l+r)/2;
		update(id*2,l,mid,pos,val);
		update(id*2+1,mid+1,r,pos,val);
		st[id]=max(st[id*2],st[id*2+1]);
	}
	int get(int id,int l,int r,int u,int v) {
		if (l>v||r<u) return -inf;
		if (u<=l&&r<=v) return st[id];
		int mid=(l+r)/2;
		return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
	}
} st1,st2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>l[i]>>r[i];
    	cprs.push_back(l[i]);
    	cprs.push_back(r[i]);
    }
    cprs.push_back(0);
    sort(cprs.begin(),cprs.end());
    cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    int m=cprs.size();
    st1.build(),st2.build();
    st1.update(1,0,m,0,0);
    st2.update(1,0,m,0,0);
    for (int i=1;i<=n;i++) {
    	l[i]=lower_bound(cprs.begin(),cprs.end(),l[i])-cprs.begin();
    	r[i]=lower_bound(cprs.begin(),cprs.end(),r[i])-cprs.begin();
    	dp[i]=st1.get(1,0,m,0,l[i]-1)+cprs[r[i]]-cprs[l[i]]+1;
    	dp[i]=max(dp[i],st2.get(1,0,m,l[i],r[i])+cprs[r[i]]);
    	st1.update(1,0,m,r[i],dp[i]);
    	st2.update(1,0,m,r[i],dp[i]-cprs[r[i]]);
    	//cout<<st1.get(1,0,m,0,l[i]-1)<<' '<<st2.get(1,0,m,l[i],r[i])<<' '<<l[i]<<' '<<r[i]<<' '<<dp[i]<<endl;
    }
    cout<<st1.get(1,0,m,0,m);
}