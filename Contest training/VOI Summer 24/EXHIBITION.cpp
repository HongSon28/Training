#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n;
long long a,c;
struct dat {
	long long a,c,x;
	bool operator < (const dat &other) const {
		if (c!=other.c) return c<other.c;
		if (a!=other.a) return a<other.a;
		return x<other.x;
	}
} x[N+5];
long long dp[N+5][2*N+5],inf=1e18;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>a>>c;
    for (int i=1;i<=n;i++) cin>>x[i].a>>x[i].c>>x[i].x;
    sort(x+1,x+1+n);
    for (int i=0;i<=N;i++)
    	for (int j=0;j<=2*N;j++) dp[i][j]=-inf; 
    dp[0][a+c]=0;
    for (int i=0;i<n;i++) {
    	for (int j=0;j<=a+c;j++) {
    		dp[i+1][j]=dp[i][j];
    		if (j-a>=x[i+1].x*x[i+1].c) {
    			dp[i+1][j-x[i+1].x*x[i+1].c]=max(dp[i+1][j-x[i+1].x*x[i+1].c],dp[i][j]+x[i+1].a);
    			//cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<j-x[i+1].x*x[i+1].c<<' '<<dp[i+1][j-x[i+1].x*x[i+1].c]<<endl;
    		}
    		else {
    			if (j>a) {
    				int t=(j-a)/x[i+1].x;
    				if (a-(x[i+1].c-t)>=0) {
    					dp[i+1][a-(x[i+1].c-t)]=max(dp[i+1][a-(x[i+1].c-t)],dp[i][j]+x[i+1].a);
    					//cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<a-(x[i+1].c-t)<<' '<<dp[i+1][a-(x[i+1].c-t)]<<endl;
    				}
    			} else {
    				if (j-x[i+1].c>=0) {
    					dp[i+1][j-x[i+1].c]=max(dp[i+1][j-x[i+1].c],dp[i][j]+x[i+1].a);
    					//cout<<i<<' '<<j<<' '<<dp[i][j]<<' '<<a-x[i+1].c<<' '<<dp[i+1][a-x[i+1].c]<<endl;
    				}
    			}
    		}
    	}
    }
    long long res=0;
    for (int i=0;i<=a+c;i++) res=max(res,dp[n][i]);
    cout<<res;
}