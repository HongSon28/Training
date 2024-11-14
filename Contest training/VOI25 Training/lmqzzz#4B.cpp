#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
pair<long long,long long>a[N+5];
long long sum[N+5],dp[N+5],res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].first;
    for (int i=1;i<=n;i++) cin>>a[i].second;
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+max(a[i].first,a[i].second);
    for (int i=1;i<=n;i++) {
    	for (int j=0;j<i;j++) 
    		if (a[j].first<a[i].first&&a[j].second<a[i].second)
    			dp[i]=max(dp[i],dp[j]+sum[i-1]-sum[j]+a[i].first+a[i].second);
    	res=max(res,dp[i]+sum[n]-sum[i]);
    }
    cout<<res;
}