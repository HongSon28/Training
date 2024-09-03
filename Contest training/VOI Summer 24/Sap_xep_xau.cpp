#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
string s;
int dp[N+5][5];
int perm[4];
char c[5];
int inf=1e9,res=inf;
int solve() {
	for (int i=0;i<=n;i++)
		for (int j=0;j<=4;j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=4;j++) 
			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+(s[i]!=c[j]);
	return min({dp[n][1],dp[n][2],dp[n][3],dp[n][4]});
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;	
    for (int i=0;i<=3;i++) perm[i]=i+1;
    do {
    	c[perm[0]]='h';
    	c[perm[1]]='d';
    	c[perm[2]]='c';
    	c[perm[3]]='s';
    	res=min(res,solve());
    } while (next_permutation(perm,perm+4));
    cout<<res;
}