#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int n;
string s;
int dp[N+5][N+5],mod=998244353;
int main() {
	freopen("brackets.inp","r",stdin);
	freopen("brackets.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    dp[0][0]=1;
    for (int i=1;i<=n;i++) {
    	if (s[i]=='(')
    		for (int j=1;j<=i;j++) dp[i][j]=dp[i-1][j-1];
    	else if (s[i]==')') 
    		for (int j=0;j<=i;j++) dp[i][j]=dp[i-1][j+1];
    	else {
    		dp[i][0]=dp[i-1][1];
    		for (int j=1;j<i;j++) {
    			dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
    			if (dp[i][j]>=mod) dp[i][j]-=mod;
    		}
    		dp[i][i]=dp[i-1][i-1];
    	}
    }
    cout<<dp[n][0];
}