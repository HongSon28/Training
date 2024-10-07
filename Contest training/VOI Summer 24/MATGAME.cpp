#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n;
long long a[8][N+5];
long long dp[N+5][256],inf=1e18,res=-inf;
vector<int>v[256];
bool check(int x,int y) {
	for (int i=0;i<7;i++) {
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
    for (int i=0;i<8;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>a[i][j];
    		res=max(res,a[i][j]);
    	}
    }
    if (res<=0) {
    	cout<<res;
    	return 0;
    }
    for (int x=0;x<256;x++) {
    	for (int y=x;y<256;y++) {
    		if (check(x,y)) {
    			v[x].push_back(y);
    			v[y].push_back(x);
    		}
    	}
    }
    for (int i=0;i<=N;i++) for (int j=0;j<256;j++) dp[i][j]=-inf;
    dp[0][0]=0;
    for (int j=1;j<=n;j++) {
    	for (int mask=0;mask<256;mask++) {
    		for (auto lastmask:v[mask]) {
				int cur=0;
				for (int i=0;i<8;i++)
					if (mask>>i&1) cur+=a[i][j];
				dp[j][mask]=max(dp[j][mask],dp[j-1][lastmask]+cur);
    		}
    		res=max(res,dp[j][mask]);
    		//cout<<j<<' '<<mask<<' '<<
    	}
    }
    cout<<res;
}