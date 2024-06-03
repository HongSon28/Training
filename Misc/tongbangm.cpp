#include<bits/stdc++.h>
using namespace std;
int n,m;
long long dp[100005];
long long a[31];
int main() {
	freopen("TONGBANGM.INP","r",stdin);
	freopen("TONGBANGM.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	dp[0]=1;
	for (int i=1;i<=n;i++) {
		for (int j=m;j>=a[i];j--) dp[j]+=dp[j-a[i]];
	}
	cout<<dp[m];
}