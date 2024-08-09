#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
int a[N+5],b[N+5],dp[N+5][N+5],mx;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		b[i-1]=a[i]-a[i-1];
	}
	for (int i=0;i<=n;i++) dp[0][i]=0;
	for (int i=1;i<=n-4;i++) {
		for (int j=i+4;j<=n;j++) {
			if (b[i]==b[j]) dp[i][j]=min(dp[i-1][j-1]+1,j-i-1);
			else dp[i][j]=0;
			mx=max(mx,dp[i][j]);
		}
	}
	if (mx>=4) cout<<mx+1;
	else cout<<0;
}