#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n,l,r;
int a[N+5];
long long f[N+5],dp[N+5],cnt[N+5];
int res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		cnt[a[i]]++;
	}
	for (int i=N;i>=1;i--) {
		for (int j=i;j<=N;j+=i) f[i]+=cnt[j];
		dp[i]=f[i]*(f[i]-1)/2;
		for (int j=i*2;j<=N;j+=i) dp[i]-=dp[j];
		if (dp[i]&&!cnt[i]) {
			dp[i]+=f[i];
			cnt[i]++;
			res++;
		}
	}
	cout<<res<<'\n';
	for (int i=l;i<=r;i++) cout<<dp[i]<<' ';
}