#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
int a[N+5];
vector<int>cprs;
long long st[N*4+5],mod=1e9+7;
void update(int id,int l,int r,int pos,long long val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]+=val;
		st[id]%=mod;
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id]=(st[id*2]+st[id*2+1])%mod;
}
long long get(int id,int l,int r,int u,int v) {
	if (u>r||v<l||u>v) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return (get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v))%mod; 
}
int main() {
	freopen("CINCSEQ.INP","r",stdin);
	freopen("CINCSEQ.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		cprs.push_back(a[i]);
	}
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=1;i<=n;i++) a[i]=lower_bound(cprs.begin(),cprs.end(),a[i])-cprs.begin()+1;
	for (int i=1;i<=n;i++) {
		long long temp=get(1,1,N,1,a[i]-1)+1;
		update(1,1,N,a[i],temp);
	}
	cout<<get(1,1,N,1,N);
}