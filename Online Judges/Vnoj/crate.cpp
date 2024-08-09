#include<bits/stdc++.h>
using namespace std;
const int N=3e5,M=1e5;
int n;
struct dat{
	int a,h,id;
	bool operator < (const dat &other) const {
		if (a!=other.a) return a<other.a;
		return h<other.h;
	}
} a[N+5];
int res[N+5];
int st[M*4+5];
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]+=val;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=st[id*2]+st[id*2+1];
} 
int get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i].a>>a[i].h;
    	a[i].id=i;
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
    	if (i>1&&a[i].a==a[i-1].a&&a[i].h==a[i-1].h) res[a[i].id]=res[a[i-1].id];
    	else res[a[i].id]=get(1,0,M,0,a[i].h);
    	update(1,0,M,a[i].h,1);
    }
    for (int i=1;i<=n;i++) cout<<res[i]<<'\n';
}