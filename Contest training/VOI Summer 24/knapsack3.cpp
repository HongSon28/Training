#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m,p;
int w[N+5],v[N+5],a[N+5];
long long dp[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>w[0]>>v[0]>>a[0];
    	int tw=w[0],tv=v[0];
    	int cur=1,sum=1;
    	while (sum<=a[0]) {
    		w[++p]=w[0];
    		v[p]=v[0];
    		cur*=2;
    		w[0]*=2;
    		v[0]*=2;
    		sum+=cur;
    	}
    	sum-=cur;
    	if (a[0]-sum>0) {
    		w[++p]=tw*(a[0]-sum);
    		v[p]=tv*(a[0]-sum);
    	}
    }
    for (int i=1;i<=p;i++) {
    	//cout<<w[i]<<' '<<v[i]<<endl;
    	for (int W=m;W>=w[i];W--) dp[W]=max(dp[W-w[i]]+v[i],dp[W]);
    }
    long long res=0;
    for (int i=1;i<=m;i++) res=max(res,dp[i]);
    cout<<res;
}