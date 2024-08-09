#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n,k;
long long a[N+5],dp[N+5][N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int len=2;len<=n;len++) {
    	for (int i=1;i+len-1<=n;i++) {
    		int j=i+len-1;
    		for (int t=1;t<=k;t++) {
    			dp[i][j][t]=max({dp[i+1][j][t],dp[i][j-1][t],dp[i][j][t-1]});
    			dp[i][j][t]=max({dp[i][j][t],dp[i+1][j-1][t-1]+abs(a[i]-a[j]),dp[i+2][j][t-1]+abs(a[i]-a[i+1]),dp[i][j-2][t-1]+abs(a[j-1]-a[j])});
    		}
    	}
    }
    cout<<dp[1][n][k];
}