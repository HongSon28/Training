#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n,k;
long long a[N+5],dp[N+5];
long long res=2e9;
bool check(long long d) {
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++) {
		dp[i]=i-1;
		for (int j=i-1;j>=1;j--) {
			if (d*(i-j)>=abs(a[i]-a[j])) dp[i]=min(dp[i],dp[j]+(i-j-1));
		}
		if (dp[i]+(n-i)<=k) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long lo=0,hi=2e9;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (check(mid)) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
    cout<<res;
}