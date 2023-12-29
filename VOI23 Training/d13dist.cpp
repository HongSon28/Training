#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long k;
pair<int,int>p[N+5];
long long st[N*4+5];
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
long long get(int id,int l,int r,int u,int v) {
	if (l>v||r<u) return 0;
	if (u<=l&&r<=v) return st[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
long long cnt(int d) {
	int l=1;
	long long ans=0;
	memset(st,0,sizeof(st));
	for (int r=1;r<=n;r++){
		while (p[r].first-p[l].first>d) {
			update(1,0,N,p[l].second);
			l++;
		}
		ans+=r-l+get(1,0,N,max(0,p[r].second-d),min(N,p[r].second+d));
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+n);
	int lo=0,hi=2e5,res=0;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		long long temp=cnt(mid);
		if (temp>=k) {
			res=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<res;
}
