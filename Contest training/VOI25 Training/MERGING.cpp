#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n,q;
long long l[N+5],r[N+5];
long long a[N+5],sum[N+5],dp[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for (int i=1;i<n;i++) {
    	a[i]=l[i+1]-r[i];
    	sum[i]=sum[i-1]+a[i];
    	dp[i][i+1]=(a[i]+1)/2;
    }
    for (int len=3;len<=n;len++) {
    	for (int i=1;i+len-1<=n;i++) {
    		int j=i+len-1;
    		long long temp=sum[j-1]-sum[i-1];
    		temp=(temp+j-i)/(j-i+1);
    		dp[i][j]=max({dp[i+1][j],dp[i][j-1],temp});
    	}
    }
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	cout<<dp[l][r]<<'\n';
    }
}