#include<bits/stdc++.h>
using namespace std;
const int N=500;
string s;
int n;
long long mod=1e9+7,dp[N+5][N+5];
bool check(char x,char y) {
	if (x=='?') return (y==')'||y==']'||y=='}');
	if (y=='?') return (x=='('||x=='['||x=='{');
	if (x=='(') return (y==')');
	if (x=='[') return (y==']');
	if (x=='{') return (y=='}');
	return false;
}
long long f(int l,int r) {
	if (l>r) return 1;
	if (dp[l][r]!=-1) return dp[l][r];
	long long sum=0;
	for (int i=l+1;i<=r;i+=2) {
		if (s[l]=='?'&&s[i]=='?') {
			sum+=f(l+1,i-1)*f(i+1,r)*3%mod;
			sum%=mod;
		} else if (check(s[l],s[i])) {
			sum+=f(l+1,i-1)*f(i+1,r)%mod;
			sum%=mod;
		}
	}
	//cout<<l<<' '<<r<<' '<<sum<<endl;
	dp[l][r]=sum;
	return sum;
}
int main() {
	memset(dp,-1,sizeof(dp));
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	n=s.size();
	s=' '+s;
	if (n%2==1) cout<<0;
	else cout<<f(1,n);
}