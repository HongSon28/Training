#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,p,k;
int s1[N+5],s2[N+5],s3[N+5],t1[N+5],t2[N+5],dp[N+5][N+5],temp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>p>>k;
    cin>>temp;
    while (temp--) {
    	int x;
    	cin>>x;
    	t1[x]=1;
    }
    cin>>temp;
    while (temp--) {
    	int x;
    	cin>>x;
    	t2[x]=1;
    }
    for (int i=1;i<=n;i++) {
    	s1[i]=s1[i-1]+t1[i];
    	s2[i]=s2[i-1]+t2[i];
    	s3[i]=s3[i-1]+(t1[i]|t2[i]);
    }
    for (int i=1;i<=n;i++) {
    	dp[i][0]=dp[i-1][0];
    	for (int j=1;j<=p;j++) {
    		dp[i][j]=dp[i-1][j];
    		int cur=min(k,i);
    		dp[i][j]=max(dp[i][j],dp[i-cur][j-1]+max(s1[i]-s1[i-cur],s2[i]-s2[i-cur]));
    		if (j>=2) dp[i][j]=max(dp[i][j],dp[i-cur][j-2]+s3[i]-s3[i-cur]);
    	}
    }
    cout<<dp[n][p];
}