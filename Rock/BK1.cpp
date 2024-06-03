#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,k,st;
string s;
long long dp[N+5][N+5],mod=1e9+7;
long long f(int i,int sum) {
	if (dp[i][sum]!=-1) return dp[i][sum];
	if (sum>st||sum<0) return 0;
	if (i==n+1&&sum==st) return 1;
	else if (i==n+1) return 0;
	long long cur=0;
	if (s[i]=='(') 
		cur=(f(i+1,sum)+f(i+1,sum-1))%mod; 
	else 
		cur=(f(i+1,sum)+f(i+1,sum+1))%mod; 
	return dp[i][sum]=cur;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k>>s;
	n=s.size();
	s=' '+s;
	memset(dp,-1,sizeof(dp));
	st=k;
	long long res1=f(1,k);
	st=k-1;
	memset(dp,-1,sizeof(dp));
	long long res2=f(1,k-1);
	//cout<<res1<<' '<<res2<<endl;
	cout<<((res1-res2)%mod+mod)%mod;
}