#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=710;
int n,k,q;
int dp[M+5][N+5],res[N+5],mod=1e9+7;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void sub(int &x,int y) {
	x-=y;
	if (x<0) x+=mod;
}
int main() {
	//freopen("SUMLOVE.INP","r",stdin);
	//freopen("SUMLOVE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;	
    dp[0][0]=1;
    for (int i=1;i<=M;i++) {
    	for (int j=i;j<=N;j++) {
    		add(dp[i][j],dp[i-1][j-i]);
    		if (j>=(n+1)) sub(dp[i][j],dp[i-1][j-(n+1)]);
    		add(dp[i][j],dp[i-1][j-i]);
    		if (j>=(n+1)) sub(dp[i][j],dp[i-1][j-(n+1)]);
    		add(dp[i][j],dp[i][j-i]);
    		if (i>=2) {
    			add(dp[i][j],dp[i-2][j-i]);
    			if (j>=2*(n+1)) sub(dp[i][j],dp[i-2][j-2*(n+1)]);
    		}
    		//cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
    	}
    	for (int j=1;j<=N;j++) add(res[j],dp[i][j]);
    }
    cin>>q;
    while (q--) {
    	cin>>k;
    	cout<<res[k]<<'\n';
    }
}