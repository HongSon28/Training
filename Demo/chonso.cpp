#include<bits/stdc++.h>
using namespace std;
int n;
long long a[21][21];
pair<long long,long long>dp[21][(1<<21)];
long long inf=1e15;
int main() {
	freopen("CHONSO.INP","r",stdin);
	freopen("CHONSO.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++)
    	for (int j=0;j<n;j++)
    		cin>>a[i][j];
    for (int i=0;i<=n;i++)
    	for (int j=0;j<=(1<<21);j++) dp[i][j]={inf,0};
    dp[0][0]={0,1};
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<n;j++) {
    		for (int mask=0;mask<(1<<n);mask++) {
    			if (mask&(1<<j)) continue;
    			if (dp[i][mask|(1<<j)].first>dp[i-1][mask].first+a[i][j]) {
    				dp[i][mask|(1<<j)].first=dp[i-1][mask].first+a[i][j];
    				dp[i][mask|(1<<j)].second=dp[i-1][mask].second;
    			} else if (dp[i][mask|(1<<j)].first==dp[i-1][mask].first+a[i][j]) {
    				dp[i][mask|(1<<j)].second+=dp[i-1][mask].second;
    			}
    		}
    	}
    }
    cout<<dp[n][(1<<n)-1].first<<'\n'<<dp[n][(1<<n)-1].second;
}