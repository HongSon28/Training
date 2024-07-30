#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n;
string s;
int dp[N+5][N+5][N+5];
int f(int l,int r);
int f(int l,int r,int x) {
	if (dp[l][r][x]!=-1) return dp[l][r][x];
	if (l==r) return dp[l][r][x]=(x+1)*(x+1);
	if (l>r) return dp[l][r][x]=x*x;
	int temp=f(l,r-1,0)+(x+1)*(x+1);
	for (int k=l;k<r;k++) if (s[k]==s[r]) temp=max(temp,f(k+1,r-1,0)+f(l,k,x+1));
	return dp[l][r][x]=temp;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	s=' '+s;	
	memset(dp,-1,sizeof(dp));
	cout<<f(1,n,0);
}