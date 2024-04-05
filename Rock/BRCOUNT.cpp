#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
string s;
long long dp[N+5][N+5],mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	n=s.size();
	s=' '+s;
	dp[0][0]=1;
	for (int i=1;i<=n;i++) {
		if (s[i]=='(') 
			for (int j=1;j<=n;j++) 
				dp[i][j]=dp[i-1][j-1];
		else if (s[i]==')') 
			for (int j=0;j<n;j++)
				dp[i][j]=dp[i-1][j+1];
		else {
			for (int j=0;j<n;j++) 
				dp[i][j]=dp[i-1][j+1];
			for (int j=1;j<=n;j++) {
				dp[i][j]+=dp[i-1][j-1];
				dp[i][j]%=mod;
			}
		}
	}
	cout<<dp[n][0];
}