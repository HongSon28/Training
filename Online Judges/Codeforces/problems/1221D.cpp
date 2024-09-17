#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int q,n;
long long a[N+5],b[N+5];
long long dp[N+5][3],inf=1e18+5;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
    while (q--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i]>>b[i];
    		dp[i][0]=dp[i][1]=dp[i][2]=inf;
    	}
    	dp[1][0]=0;
    	dp[1][1]=b[1];
    	dp[1][2]=b[1]*2;
    	for (int i=2;i<=n;i++) {
    		for (int j=0;j<=2;j++) 
    			for (int k=0;k<=2;k++)
    				if (a[i-1]+k!=a[i]+j) dp[i][j]=min(dp[i][j],dp[i-1][k]+b[i]*j); 
    	}
    	cout<<min({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
    }
}