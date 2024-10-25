#include<bits/stdc++.h>
using namespace std;
const int N=5e3,M=2e6;
int n,m,cur;
int a[M+5];
int dp[N+5],d[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n+1;i++) {
		cin>>a[i];
		if (a[i]>0) {
			if (a[i]<=cur) {
				d[a[i]]++;
				d[cur+1]--;
			}
		} else if (a[i]<0) {
			if (cur+a[i]>=0) {
				d[0]++;
				d[cur+a[i]+1]--;	
			}
		} else {
			cur++;
			dp[0]+=d[0];
			for (int i=1;i<=cur;i++) {
				d[i]+=d[i-1];
				dp[i]+=d[i];
			}
			for (int i=0;i<=cur;i++) d[i]=0;
			for (int i=cur;i>=1;i--) dp[i]=max(dp[i],dp[i-1]);
			//cout<<i<<' '<<cur<<endl;
			//for (int i=0;i<=cur;i++) cout<<dp[i]<<' ';
			//cout<<endl;
		}
	}
	int res=0;
	for (int i=0;i<=m;i++) res=max(res,dp[i]);
	cout<<res;
}