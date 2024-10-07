#include<bits/stdc++.h>
using namespace std;
const int N=200;
int nr,ng,nb;
long long r[N+5],g[N+5],b[N+5];
long long dp[N+5][N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>nr>>ng>>nb;
    for (int i=1;i<=nr;i++) cin>>r[i];
    sort(r+1,r+nr+1,greater<int>());
    for (int i=1;i<=ng;i++) cin>>g[i];
    sort(g+1,g+ng+1,greater<int>());
    for (int i=1;i<=nb;i++) cin>>b[i];
    sort(b+1,b+nb+1,greater<int>());
    for (int i=1;i<=min(nr,ng);i++) dp[i][i][0]=dp[i-1][i-1][0]+r[i]*g[i];
    for (int i=1;i<=min(nr,nb);i++) dp[i][0][i]=dp[i-1][0][i-1]+r[i]*b[i];
    for (int i=1;i<=min(ng,nb);i++) dp[0][i][i]=dp[0][i-1][i-1]+g[i]*b[i];
    for (int i=1;i<=nr;i++) {
    	for (int j=1;j<=ng;j++) {
    		for (int k=1;k<=nb;k++) {
    			dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
    			dp[i][j][k]=max({dp[i][j][k],dp[i-1][j-1][k]+r[i]*g[j]
    										,dp[i][j-1][k-1]+g[j]*b[k]
    										,dp[i-1][j][k-1]+r[i]*b[k]});
    			//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<endl;
    		}
    	}
    }
    cout<<dp[nr][ng][nb];
}