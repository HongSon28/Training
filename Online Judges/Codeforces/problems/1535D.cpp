#include<bits/stdc++.h>
using namespace std;
const int N=(1<<18)+5;
int k,n,q;
string s;
map<pair<int,int>,int>mp;
int pos[N+5],a[N*4+5],st[N*4+5];
int l[N+5],r[N+5];
void build(int id,int l,int r) {
	pos[mp[{l,r}]]=id;
	a[id]=mp[{l,r}];
	if (l==r) {
		st[id]=1;
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	if (s[a[id]]=='0') st[id]=st[id*2];
	else if (s[a[id]]=='1') st[id]=st[id*2+1];
	else st[id]=st[id*2]+st[id*2+1];
}
void update(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return;
	if (l==u&&r==v) {
		if (s[a[id]]=='0') st[id]=st[id*2];
		else if (s[a[id]]=='1') st[id]=st[id*2+1];
		else st[id]=st[id*2]+st[id*2+1];
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	if (s[a[id]]=='0') st[id]=st[id*2];
	else if (s[a[id]]=='1') st[id]=st[id*2+1];
	else st[id]=st[id*2]+st[id*2+1];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k>>s;
	n=(1<<k);
	int cur=0;
	for (int t=1;t<=k;t++) {
		int len=(1<<t);
		for (int i=1;i+len-1<=n;i+=len) {
			mp[{i,i+len-1}]=++cur;
			l[cur]=i,r[cur]=i+len-1;
		}
	}
	s=' '+s;
	build(1,1,n);
	cin>>q;
	while (q--) {
		int p;
		char c;
		cin>>p>>c;
		s[p]=c;
		update(1,1,n,l[p],r[p]);
		cout<<st[1]<<'\n'; 
	}
}