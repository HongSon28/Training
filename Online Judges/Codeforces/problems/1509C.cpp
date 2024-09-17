#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n;
long long dp[N+5][N+5],s[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n);
    for (int len=2;len<=n;len++) {
    	for (int i=1;i+len-1<=n;i++) {
    		int j=i+len-1;
    		dp[i][j]=min(dp[i+1][j],dp[i][j-1])+s[j]-s[i];
    	}
    }
    cout<<dp[1][n];
}