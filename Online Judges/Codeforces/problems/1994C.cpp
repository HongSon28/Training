#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,x;
long long a[N+5];
int nxt[N+5];
long long dp[N+5];
long long f(int i) {
	if (i>n) return 0;
	if (dp[i]!=-1) return dp[i];
	if (nxt[i]==-1) return dp[i]=0;
	long long ans=1+f(nxt[i]+1);
	return dp[i]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>x;
		for (int i=1;i<=n;i++) cin>>a[i];
		long long sum=a[1];
		int j=1;
		for (int i=1;i<=n;i++) {
			while (j<n&&sum<=x) {
				j++;
				sum+=a[j];
			}
			if (sum>x) nxt[i]=j;
			else nxt[i]=-1;
			sum-=a[i];
			//cout<<nxt[i]<<' ';
		}
		long long res=0;
		memset(dp,-1,sizeof(dp));
		for (int i=1;i<=n;i++) res+=f(i);
		cout<<(long long)n*(n-1)/2+n-res<<'\n';
	}
}