#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long a[N+5],b[N+5][11];
long long dp[N+5][11][11],inf=1e18+5,res=-inf;
void maxi(long long &x,long long y) {
	if (x<y) x=y;
}
int main() {
	freopen("watermelon.inp","r",stdin);
    freopen("watermelon.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	b[i][0]=1;
    	cin>>b[i][1];
    	for (int j=2;j<=k;j++) b[i][j]=b[i][j-1]*b[i][1];
    }
    for (int i=1;i<=n;i++) 
    	for (int x=0;x<=k;x++)
    		for (int y=0;y<=k;y++) 
    			dp[i][x][y]=-inf;
    for (int i=0;i<n;i++) {
    	for (int x=0;x<=k;x++) {
    		for (int y=0;y<=x;y++) {
    			for (int op=0;op<=k-x;op++) {
    				for (int cl=0;cl<=y;cl++) {
    					maxi(dp[i+1][x+op][y+op-cl],max(dp[i][x][y],0ll)+a[i+1]*b[i+1][y+op-cl]);
    					maxi(res,dp[i+1][x+op][y+op-cl]);
    				}
    			}
    		}
    	}
    }
    for (int x=0;x<=k;x++)
    	for (int y=0;y<=x;y++) maxi(res,dp[n][x][y]);
    cout<<res;
}