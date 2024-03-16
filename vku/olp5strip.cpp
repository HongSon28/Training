#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k;
long long dp[N+5],mod=1e9+7,sum[N+5];
int d[N+5];
vector<pair<int,int>>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=k;i++) {
    	int l,r;
    	cin>>l>>r;
    	d[l]++;
    	d[r+1]--;
    }
    int l,r;
    for (int i=1;i<=n+1;i++) {
    	d[i]+=d[i-1];
    	if (d[i]!=0) {
    		if (d[i-1]==0) l=r=i;
    		else r++;
    	} else if (d[i-1]!=0) v.push_back({l,r});
    }
    dp[1]=1;
    sum[1]=1;
    for (int i=2;i<=n;i++) {
    	for (auto [l,r]:v) {
    		int hi=i-l,lo=i-r;
    		if (hi<1) continue;
    		lo=max(lo,1);
    		dp[i]+=sum[hi]-sum[lo-1];
    		dp[i]=(dp[i]%mod+mod)%mod;
    		//cout<<i<<' '<<lo<<' '<<hi<<' '<<dp[i]<<endl;
    	}
    	sum[i]=(sum[i-1]+dp[i])%mod;
    }
    cout<<dp[n];
}