#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int n;
long long a[N+5];
long long dp[N+5][N+5];
long long f(int l,int r) {
	if (dp[l][r]!=-1) return dp[l][r];
	if (r-l<=1) return 0;
	for (int k=l+1;k<r;k++) dp[l][r]=max(dp[l][r],f(l,k)+f(k,r)+a[l]*a[r]);
	return dp[l][r]; 
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