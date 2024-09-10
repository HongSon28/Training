#include<bits/stdc++.h>
using namespace std;
const int N=5e4;
int n,q;
int a[N+5];
int l,r;
pair<int,int>st[N*4+5];
int inf=1e9;
void build(int id,int l,int r) {
	if (l==r) {
		st[id]={a[l],a[l]};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].first=min(st[id*2].first,st[id*2+1].first);
	st[id].second=max(st[id*2].second,st[id*2+1].second);
}
pair<int,int>get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return {inf,-inf};
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	pair<int,int>g1=get(id*2,l,mid,u,v),g2=get(id*2+1,mid+1,r,u,v);
	return {min(g1.first,g2.first),max(g1.second,g2.second)};
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while (q--) {
		cin>>l>>r;
		pair<int,int>p=get(1,1,n,l,r);
		cout<<p.second-p.first<<'\n';
	}
}