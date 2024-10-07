#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n;
int a[4][N+5];
int dp[N+5][16],inf=1e9,res=-inf;
bool check(int x,int y) {
	for (int i=0;i<3;i++) {
		if ((x>>i&1)&&(x>>(i+1)&1)) return false;
		if ((y>>i&1)&&(y>>(i+1)&1)) return false;
	}
	return ((x&y)==0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=0;i<4;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>a[i][j];
    		res=max(res,a[i][j]);
    	}
    }
    if (res<=0) {
    	cout<<res;
    	return 0;
    }
    for (int i=0;i<=N;i++) for (int j=0;j<16;j++) dp[i][j]=-inf;
    dp[0][0]=0;
    for (int j=1;j<=n;j++) {
    	for (int mask=0;mask<16;mask++) {
    		for (int lastmask=0;lastmask<16;lastmask++) {
    			if (check(mask,lastmask)) {
    				int cur=0;
    				for (int i=0;i<4;i++)
    					if (mask>>i&1) cur+=a[i][j];
    				dp[j][mask]=max(dp[j][mask],dp[j-1][lastmask]+cur);
    			}
    		}
    		res=max(res,dp[j][mask]);
    	}
    }
    cout<<res;
}