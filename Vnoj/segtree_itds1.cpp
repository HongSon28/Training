#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
multiset<int>st[N*4+5];
int n,m;
int inf=1e9+5;
int a[N+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[id].insert(a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	if (st[id*2].size()>=st[id*2+1].size()) st[id]=st[id*2];
	for (auto x:st[id*2+1]) st[id].insert(x);
}
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id].erase(st[id].lower_bound(a[pos]));
		st[id].insert(val);
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id].erase(st[id].lower_bound(a[pos]));
	st[id].insert(val);
}
int get(int id,int l,int r,int u,int v,int val) {
	if (u>r||v<l) return inf;
	if (u<=l&&r<=v) {
		auto it=st[id].lower_bound(val);
		if (it==st[id].end()) return inf;
		return *it;
	}
	int mid=(l+r)/2;
	return min(get(id*2,l,mid,u,v,val),get(id*2+1,mid+1,r,u,v,val));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while (m--) {
    	int type;
    	cin>>type;
    	if (type==1) {
    		int i,v;
    		cin>>i>>v;
    		update(1,1,n,i,v);
    		a[i]=v;
    	} else {
    		int l,r,k;
    		cin>>l>>r>>k;
    		int temp=get(1,1,n,l,r,k);
    		if (temp==inf) cout<<-1<<'\n';
    		else cout<<temp<<'\n';
    	}
    }
}