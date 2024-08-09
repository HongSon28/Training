#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long p,c,a[N+5],s[6],dp[N+5][(1<<6)],good[N+5][6],inf=1e18;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>p>>c;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=0;i<m;i++) cin>>s[i];
    for (int i=0;i<=n;i++)
    	for (int j=0;j<(1<<m);j++) 
    		dp[i][j]=-inf;
    dp[0][0]=0;
    for (int i=0;i<=n;i++) 
    	for (int j=0;j<6;j++)
    		good[i][j]=-inf;
	good[0][0]=0;
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<m;j++) {
    		for (int mask=0;mask<(1<<m);mask++) {
    			if (!(mask>>j&1)) continue;
    			dp[i][mask]=max(dp[i][mask],good[i-s[j]][])
    		}
    	}
    }
}