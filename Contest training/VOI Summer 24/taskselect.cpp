#include<bits/stdc++.h>
using namespace std;
int t;
int n,k;
string m;
int a[11];
long long dp[101][11][10000];
long long mod=1e9+7;
long long f(int i,int j,int carry) {
	if (i==n) return carry==0;
	if (dp[i][j][carry]!=-1) return dp[i][j][carry];
	if (j==k) {
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
	freopen("TASKSELECT.INP","r",stdin);
	freopen("TASKSELECT.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		memset(dp,-1,sizeof(dp));
		cin>>k>>n;
		for (int i=1;i<=k;i++) {
			a[i-1]=i;
			n-=i;
		}
		m=to_string(n);
		n=m.size();
		reverse(m.begin(),m.end());
		cout<<f(0,0,0)<<'\n';
	}
}