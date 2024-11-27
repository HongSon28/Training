#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],p[N+5];
int dp[N+5],inf=1e9,st[N*4+5];
void update(int id,int l,int r,int pos,int val) {
	if (l>pos||r<pos) return;
	if (l==r) {
		st[id]=max(st[id],val);
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
vector<long long>cprs;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		p[i]=p[i-1]+a[i];
		cprs.push_back(p[i]);
	}
	cprs.push_back(0);
	sort(cprs.begin(),cprs.end());
	cprs.resize(unique(cprs.begin(),cprs.end())-cprs.begin());
	for (int i=0;i<=n;i++) p[i]=lower_bound(cprs.begin(),cprs.end(),p[i])-cprs.begin()+1;
	dp[0]=1;
	for (int i=1;i<=N*4;i++) st[i]=-inf;
	update(1,1,n+1,p[0],1);
	for (int i=1;i<=n;i++) {
		dp[i]=get(1,1,n+1,1,p[i])+1;
		update(1,1,n+1,p[i],dp[i]);
	}
	if (dp[n]<0) cout<<-1;
	else cout<<n+1-dp[n];
}