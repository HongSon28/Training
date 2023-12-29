#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m,k;
int a[N+5];
long long res,inf=1e18;
vector<vector<long long>>dp;
deque<int>dq;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>k;
    dp.resize(k+1);
    for (int i=0;i<=k;i++) dp[i].resize(n+1);
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		dp[1][i]=a[i];
	}
	dp[1][0]=-inf;
	res=-inf;
	for (int i=2;i<=k;i++) {
		dp[i][0]=-inf;
		while (!dq.empty()) dq.pop_back();
		for (int j=1;j<=n;j++) {
			while (!dq.empty()&&dp[i-1][dq.back()]<=dp[i-1][j-1]) dq.pop_back();
			dq.push_back(j-1);
			while (dq.front()<j-m) dq.pop_front();
			dp[i][j]=dp[i-1][dq.front()]+1ll*a[j]*i;
			if (i==k) res=max(res,dp[i][j]);
		}
	}
	cout<<res;
}