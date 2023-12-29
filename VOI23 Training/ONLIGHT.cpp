#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,p,k;
int s1[N+5],s2[N+5],s3[N+5],res,temp;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>p>>k;
    p=min(p,2*n/k+2);
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
    int dp1[p+1][n+1][k+1]={},dp2[p+1][n+1][k+1]={};
    for (int i=0;i<=p;i++) {
    	for (int j=0;j<=n;j++) {
    		for (int t=0;t<=k;t++) {
    			dp1[i][j][t]=dp2[i][j][t]=0;
    		}
    	}
    }
    for (int q=1;q<=p;q++)
    cout<<dp[n][p];
}