#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
int a[N+5],res[N+5],Left[N+5],Right[N+5],pos[N+5],ql[N+5],qr[N+5];
vector<int>v;
vector<pair<int,int>>st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	st[id].push_back({qr[val],val});
	if (l==r) return;
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
} 
void update2(int id,int l,int r,int u,int v,int p1,int p2) {
	if (u>r||v<l) return;
	if (u<=l&&r<=v) {
		st[id].push_back({p1,-1});
		st[id].push_back({p2,-2});
		return;
	}
	int mid=(l+r)/2;
	update2(id*2,l,mid,u,v,p1,p2);
	update2(id*2+1,mid+1,r,u,v,p1,p2);
}
void solve(int id,int l,int r) {
	sort(st[id].begin(),st[id].end());
	int cnt=0;
	for (auto p:st[id]) {
		//cout<<l<<' '<<r<<' '<<p.first<<' '<<p.second<<' '<<cnt<<endl;
		if (p.second==-1) cnt++;
		else if (p.second==-2) cnt--;
		else res[p.second]+=cnt;
	}
	if (l==r) return;
	int mid=(l+r)/2;
	solve(id*2,l,mid);
	solve(id*2+1,mid+1,r);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for (int i=1;i<=n;i++) {
		a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		Left[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	for (int i=1;i<=n;i++) pos[a[i]]=n+1;
	for (int i=n;i>=1;i--) {
		Right[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	Right[n+1]=n+1;
	for (int i=1;i<=q;i++) {
		cin>>ql[i]>>qr[i];
		update(1,1,n,ql[i],i);
	}
	for (int i=1;i<=n;i++) {
		int temp=Right[i];
		if (temp==n+1) continue;
		update2(1,1,n,Left[i]+1,i,temp,Right[temp]);
	}
	solve(1,1,n);
	for (int i=1;i<=q;i++) cout<<res[i]<<'\n';
}