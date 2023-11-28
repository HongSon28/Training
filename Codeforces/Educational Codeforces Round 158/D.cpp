#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
int a[N+5],dp[N+5][2];
int res=INT_MAX;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	int cur=0;
	for (int i=1;i<=n;i++) {
		cur++;
		dp[i][0]=max({dp[i-1][0],a[i],cur+n-i});
		cur=max(cur,a[i]);
	}
	cur=-1;
	for (int i=n;i>=1;i--) {
		cur++;
		dp[i][1]=max({dp[i+1][1],a[i],cur+i-1});
		cur=max(cur,a[i]);
	}
	for (int i=1;i<=n;i++) res=min(res,max(dp[i][0],dp[i][1]));
	cout<<res;
}