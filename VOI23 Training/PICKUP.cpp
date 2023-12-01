#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,m;
long long a[N+5],sum[N+5],inf=1e18;
vector<long long>dp0(N+5),dp1(N+5);
long long cost(int l,int r) {
	if (l>r) return inf;
	long long dif=r-l+1;
	return a[r]*dif-(sum[r]-sum[l-1]);
}
void calc(int l,int r,int optl,int optr) {
	if (l>r) return;
	int mid=(l+r)/2;
	pair<long long,int>best={inf,-1};
	for (int k=optl;k<=optr;k++) {
		best=min(best,{dp0[k-1]+cost(k,mid),k});
	}
	dp1[mid]=best.first;
	int opt=best.second;
	calc(l,mid-1,optl,opt);
	calc(mid+1,r,opt,optr);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("PICKUP.INP","r",stdin);
	freopen("PICKUP.OUT","w",stdout);
	cin>>n>>m;
	m=min(n,m);
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++) dp0[i]=a[i]*i-sum[i];
	for (int i=2;i<=m;i++) {
		calc(1,n,1,n);
		dp0=dp1;
	} 
	cout<<dp0[n];
}
