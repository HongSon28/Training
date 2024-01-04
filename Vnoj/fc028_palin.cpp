#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
string s;
int dp[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;
	for (int len=2;len<=n;len++) {
		for (int i=1;i+len-1<=n;i++) {
			int j=i+len-1;
			if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
			else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
		}
	}
	cout<<dp[1][n];
}