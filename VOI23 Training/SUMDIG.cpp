#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5],mn,mx;
string s;
pair<long long,long long>dp[11][2];
long long res;
pair<long long,long long>f(int i,int less) {
	if (i==m) return {0,1};
	if (dp[i][less]!=(pair<long long,long long>){-1,-1}) return dp[i][less];
	int lim;
	if (less) lim=9;
	else lim=s[i]-'0';
	pair<long long,long long>ans={0,0};
	for (int c=0;c<=lim;c++) {
		pair<long long,long long>temp=f(i+1,less|(c<s[i]-'0'));
		ans.first+=c*temp.second+temp.first;
		ans.second+=temp.second;
	}
	return dp[i][less]=ans;
}
long long calc(int x) {
	s=to_string(x);
	m=s.size();
	memset(dp,-1,sizeof(dp));
	return f(0,0).first;	
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=2;i<=n;i++) {
		int mx=max(a[i],a[i-1]);
		int mn=min(a[i],a[i-1]);
		res=max(res,calc(mx)-calc(mn-1));
	}
	cout<<res;
}