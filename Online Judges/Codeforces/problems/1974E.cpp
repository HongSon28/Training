#include<bits/stdc++.h>
using namespace std;
const int N=50,M=5e4;
int t,m;
long long x;
long long h[N+5];
int c[N+5];
long long dp[N+5][M+5],inf=1e18;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	int sum=0,res=0;
    	cin>>m>>x;
    	for (int i=1;i<=m;i++) {
    		cin>>c[i]>>h[i];
    		sum+=h[i];
    		//cout<<c[i]<<' '<<h[i]<<endl;
    	}
    	for (int i=0;i<=m;i++) {
    		for (int v=0;v<=sum;v++) dp[i][v]=inf;
    	}
    	dp[0][0]=0;
    	for (int i=1;i<=m;i++) {
    		for (int v=0;v<=sum;v++) {
    			dp[i][v]=dp[i-1][v];
    			if (v>=h[i]) dp[i][v]=min(dp[i][v],dp[i-1][v-h[i]]+c[i]);
    			if (dp[i][v]>(i-1)*x) dp[i][v]=inf;
    			if (dp[i][v]!=inf) res=max(res,v);
    		}
    	}
    	cout<<res<<'\n';
    }
}