#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
int a[N+5];
int dp[N+5][N+5];
int f(int l,int r) {
	if (l>r) return 0;
	if (l==r) return 1;
	if (dp[l][r]!=-1) return dp[l][r];
	int mn=f(l+1,r)+1;
	if (a[l]==a[l+1]) mn=min(mn,f(l+2,r)+1);
	for (int i=l+2;i<=r;i++) {
		if (a[i]==a[l]) mn=min(mn,f(l+1,i-1)+f(i+1,r));
	}
	return dp[l][r]=mn;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<f(1,n);
}