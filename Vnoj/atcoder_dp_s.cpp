#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
string k;
int n,d;
long long dp[N+5][101][2],mod=1e9+7;
long long f(int i,int rem,int less) {
	if (i==n) return rem==0;
	if (dp[i][rem][less]!=-1) return dp[i][rem][less];
	long long ans=0;
	for (char c='0';c<='9';c++) {
		if (less||c<=k[i+1]) {
			ans+=f(i+1,(rem+c-'0')%d,less||c<k[i+1]);
			ans%=mod;
		}
	} 
	return dp[i][rem][less]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>k>>d;
    n=k.size();
    k=' '+k;
    memset(dp,-1,sizeof(dp));
    cout<<(f(0,0,0)-1+mod)%mod;
}