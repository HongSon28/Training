#include<bits/stdc++.h>
using namespace std;
const int N=1000,M=100;
int t,n,k;
int dp[N+5][M+5],inf=1e9;
int a[N+5],b[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
    	cin>>n>>k;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i]>>b[i];
    		if (a[i]>b[i]) swap(a[i],b[i]);
    	}
    	for (int i=0;i<=n;i++)
    		for (int j=0;j<=k;j++)
    			dp[i][j]=inf;
    	dp[0][0]=0;
    	for (int i=1;i<=n;i++) {
    		for (int j=0;j<=k;j++) {
    			dp[i][j]=dp[i-1][j];
    			int cur=0,ci=a[i],cj=b[i];
    			for (int t=1;t<=min(a[i]+b[i],j);t++) {
    				if (ci<=cj) {
    					cur+=ci;
    					cj--;
    				} else {
    					cur+=cj;
    					ci--;
    				}
    				dp[i][j]=min(dp[i][j],dp[i-1][j-t]+cur);
    			} 
    		}
    	}
    	if (dp[n][k]==inf) cout<<-1<<'\n';
    	else cout<<dp[n][k]<<'\n';
    }	
}