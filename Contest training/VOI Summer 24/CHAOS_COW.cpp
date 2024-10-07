#include<bits/stdc++.h>
using namespace std;
const int N=16;
int n,k;
int a[N+5];
long long dp[N+5][(1<<N)+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int mask=1;mask<(1<<n);mask++) {
		for (int i=0;i<n;i++) {
			if (mask>>i&1) {
				if (__builtin_popcount(mask)==1) {
					dp[i][mask]=1;
					continue;
				}
				int curmask=mask&(~(1<<i));
				for (int j=0;j<n;j++) {
					if ((curmask>>j&1)&&(abs(a[i]-a[j])>k)) dp[i][mask]+=dp[j][curmask];
				}
			}
			if (mask==(1<<n)-1) res+=dp[i][mask];
		}
	}
	cout<<res;
}