#include<bits/stdc++.h>
using namespace std;
int n,k;
string m;
int a[11];
long long dp[101][11][10000];
long long mod=1e9+7;
long long f(int i,int j,int carry) {
	if (i==k) return carry==0;
	if (dp[i][j][carry]!=-1) return dp[i][j][carry];
	if (j==n) {
		if (carry%10==(int)m[i]-'0') 
			return dp[i][j][carry]=f(i+1,0,carry/10);
		return dp[i][j][carry]=0;
	}
	long long ans=0;
	for (int c=0;c<=9;c++) {
		ans+=f(i,j+1,carry+c*a[j]);
		if (ans>=mod) ans-=mod;
	}
	//cout<<i<<' '<<j<<' '<<carry<<' '<<ans<<endl;
	return dp[i][j][carry]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	reverse(m.begin(),m.end());
	for (int i=0;i<n;i++) cin>>a[i];
	k=m.size();
	cout<<f(0,0,0);
}