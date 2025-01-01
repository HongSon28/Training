#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n,k;
long long a[N+5],sum[N+5],dp[N+5][N+5],inf=1e18;
long long cost(int l,int r) {
	long long t=sum[r]-sum[l-1];
	return t*t;
}
void calc(int k,int l,int r,int optl,int optr) {
	if (l>r) return;
	int mid=(l+r)/2;
	pair<long long,int>opt={inf,-1};
	for (int i=optl;i<=min(optr,mid);i++) opt=min(opt,{dp[k-1][i-1]+cost(i,mid),i});
	dp[k][mid]=opt.first;
	calc(k,l,mid-1,optl,opt.second);
	calc(k,mid+1,r,opt.second,optr);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    }	
    for (int i=1;i<=n;i++) dp[1][i]=cost(1,i);
    for (int i=2;i<=k;i++) calc(i,1,n,1,n);
    cout<<dp[k][n];
}