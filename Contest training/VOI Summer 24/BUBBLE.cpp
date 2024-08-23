#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int t,n;
long long a[N+5];
long long mod=10000007;
vector<long long>cprs;
int st[N*4+5];
void build(int id,int l,int r) {
	st[id]=0;
	if (l==r) return;
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
} 
void update(int id,int l,int r,int pos) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]++;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos);
	update(id*2+1,mid+1,r,pos);
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
    cin>>t;
    for (int tt=1;tt<=t;tt++) {
    	cin>>n;
    	int res=0;
    	cprs.clear();
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		cprs.emplace_back(a[i]);
    	}
    	sort(cprs.begin(),cprs.end());
    	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
    	for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
    	build(1,1,n);
    	for (int i=1;i<=n;i++) {
    		update(1,1,n,a[i]);
    		res+=get(1,1,n,a[i]+1,n);
    	}
    	cout<<"Case "<<tt<<": "<<res%mod<<'\n';
    }
}