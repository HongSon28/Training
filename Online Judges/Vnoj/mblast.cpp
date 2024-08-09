#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n,m,k;
int dp[N+5][N+5];
string a,b;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>a>>b>>k;
	n=a.size(),m=b.size();
	a=' '+a,b=' '+b;
	for (int i=1;i<=n;i++) dp[i][0]=i*k;
	for (int i=1;i<=m;i++) dp[0][i]=i*k;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			dp[i][j]=min(dp[i-1][j-1]+abs(a[i]-b[j]),k+min(dp[i-1][j],dp[i][j-1]));
		}
	}
	cout<<dp[n][m];
}