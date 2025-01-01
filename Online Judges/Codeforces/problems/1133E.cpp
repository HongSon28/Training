#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,k;
int a[N+5];
int dp[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1;
	for (int i=1;i<=n;i++) {
		while (a[i]-a[l]>5) l++;
		dp[i][0]=dp[i-1][0];
		for (int j=1;j<=k;j++) dp[i][j]=max(dp[i-1][j],dp[l-1][j-1]+(i-l+1));
	}
	cout<<dp[n][k];
}