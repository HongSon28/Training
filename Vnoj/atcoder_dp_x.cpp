#include<bits/stdc++.h>
using namespace std;
const int N=1e3,M=2e4;
struct block{
	int w,s;
	long long v;
	bool operator < (const block &other) const {
		return w+s<other.w+other.s;
	}
}a[N+5];
int n;
long long dp[M+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i].w>>a[i].s>>a[i].v;
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) {
		for (int j=a[i].s+a[i].w;j>=a[i].w;j--) dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
	}
	for (int i=0;i<=M;i++) res=max(res,dp[i]);
	cout<<res;
}