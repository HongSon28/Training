#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n;
int dp[N+5][N+5];
string s;
int f(int l,int r) {
	if (dp[l][r]!=-1) return dp[l][r];
	if (l==r) return 1;
	if (l>r) return 0;
	int mn=f(l+1,r)+1;
	for (int i=l+1;i<=r;i++) {
		if (s[l]==s[i]) mn=min(mn,f(l+1,i-1)+f(i,r));
	}
	//cout<<l<<' '<<r<<' '<<mn<<endl;
	return dp[l][r]=mn;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(dp,-1,sizeof(dp));
    cin>>n>>s;
    s=' '+s;
    cout<<f(1,n);
}