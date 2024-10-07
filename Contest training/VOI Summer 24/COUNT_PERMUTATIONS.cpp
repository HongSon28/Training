#include<bits/stdc++.h>
using namespace std;
const int N=15;
int t,n,k;
long long dp[N+5][(1<<N)+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>k;
		if (n==1) {
			cout<<1<<'\n';
			continue;
		}
		long long res=0;
		memset(dp,0,sizeof(dp));
		for (int mask=1;mask<(1<<n);mask++) {
			for (int i=0;i<n;i++) {
				if (mask>>i&1) {
					if (__builtin_popcount(mask)==1) {
						dp[i][mask]=1;
						continue;
					}
					int curmask=mask&(~(1<<i));
					for (int j=0;j<n;j++) {
						if ((curmask>>j&1)&&(abs(i-j)<=k)) dp[i][mask]+=dp[j][curmask];
					}
				}
				if (mask==(1<<n)-1) res+=dp[i][mask];
			}
		}
		cout<<res<<'\n';
	}
}