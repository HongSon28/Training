#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5;
int sub,n,f,q;
ll p[N+5],pos[N+5];
void build_pos() {
	int l=f-1,r=f+1;
	pos[f]=1;
	for (int i=2;i<=n;i++) {
		//cout<<l<<' '<<r<<' '<<p[l]<<' '<<p[r]<<endl;
		if (r>n||(l>0&&p[l]<p[r])) {
			pos[l]=i;
			l--;
		} else {
			pos[r]=i;
			r++;
		}
	}
}
void solve12() {
	build_pos();
	while (q--) {
		char type;
		cin>>type;
		if (type=='U') {
			ll k,c;
			cin>>k>>c;
			ll o=p[k];
			p[k]=c;
			for (int i=c;i<=o-1;i++) p[i]++;
			build_pos();
		} else {
			int x;
			cin>>x;
			cout<<pos[x]<<'\n';
		}
	}
}

ll st[N*4+5],lazy[N+5];
void build(int id,int l,int r) {
	if (l==r) {
		st[id]=p[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id]=st[id*2]+st[id*2+1];
}
void down(int id,int l,int r) {
	int mid=(l+r)/2;
	ll temp=lazy[id];
	lazy[id]=0;
	lazy[id*2]+=temp;
	lazy[id*2+1]+=temp;
	st[id*2]+=(mid-l+1)*temp;
	st[id*2+1]+=(r-mid)*temp;
}
void update(int id,int l,int r,int u,int v,ll val) {
	if (u>r||l>v) return;
	if (u<=l&&r<=v) {
		st[id]+=(r-l+1)*val;
		lazy[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	down(id,l,r);
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	st[id]=st[id*2]+st[id*2+1];
}
ll get(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return 0;
	if (u<=l&&r<=v) return st[id];
	down(id,l,r);
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void solve3() {
	build(1,1,n);
	build_pos();
	while (q--) {
		char type;
		cin>>type;
		if (type=='U') {
			ll k,c;
			cin>>k>>c;
			ll o=get(1,1,n,k,k);
			update(1,1,n,k,k,c-get(1,1,n,k,k));
			update(1,1,n,c,o-1,1);
			for (int i=1;i<=n;i++) p[i]=get(1,1,n,i,i);
			build_pos();
		} else {
			int x;
			cin>>x;
			cout<<pos[x]<<'\n';
		}
	}
}
int main() {
	freopen("VI.INP","r",stdin);
	freopen("VI.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>sub;
	cin>>n>>q>>f;
	for (int i=1;i<=n;i++) 
		cin>>p[i];
	if (sub<=2) solve12();
	else solve3();
}