#include<bits/stdc++.h>
using namespace std;
const int N=100,M=1e6;
int n,x;
int c[N+5];
int dp[M+5],inf=1e9;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>c[i];
    dp[0]=0;
    for (int i=1;i<=x;i++) {
    	dp[i]=inf;
		for (int j=1;j<=n;j++) {
			if (i>=c[j]) dp[i]=min(dp[i],dp[i-c[j]]+1);
		}
	}
	if (dp[x]==inf) cout<<-1;
	else cout<<dp[x];
}