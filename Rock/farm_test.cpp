#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,k,p,q;
long long a[N+5],dp[N+5][N+5],res;
bool used[N+5];
void trace(int i,int j) {
	
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k>>q>>p;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<=q;j++) {
    		dp[i][j]=dp[i-1][j];
    		if (j<=p) dp[i][j]=max(dp[i][j],a[i]*j);
    		if (i-k>=1) {
    			for (int t=1;t<=min(j,p);t++) dp[i][j]=max(dp[i][j],dp[i-k][j-t]+t*a[i]);
    		}
    		res=max(res,dp[i][j]);
    	}
    }
    cout<<res;
}