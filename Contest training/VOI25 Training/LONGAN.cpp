#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
pair<int,int>p[N+5];
int dp[N+5],inf=1e9;
multiset<int>mn,mx;
vector<int>v[N+5];
int st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=val;
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
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=m;i++) {
		cin>>p[i].first>>p[i].second;
		mn.insert(p[i].second);
		v[p[i].first].push_back(p[i].second);
	}
	for (int i=1;i<=N*4;i++) st[i]=-inf;
	update(1,0,n+1,n+1,0);
	for (int i=n;i>=0;i--) {
		for (auto r:v[i+1]) {
			mn.erase(mn.lower_bound(r));
			mx.insert(r);
		}
		int l,r;
		if (mn.empty()) l=1;
		else l=(*mn.rbegin())+1;
		if (mx.empty()) r=n+1;
		else r=(*mx.begin());
		if (l>r) dp[i]=-inf;
		else dp[i]=get(1,0,n+1,l,r)+1;
		update(1,0,n+1,i,dp[i]);
	}
	if (dp[0]<=0) cout<<-1;
	else cout<<dp[0]-1;
}