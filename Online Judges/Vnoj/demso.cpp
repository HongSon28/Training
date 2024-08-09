#include<bits/stdc++.h>
using namespace std;
long long a,b,d,k,n;
long long dp[16][16][11][2][2];
string s;
long long f(int i,int cur,int last,int less,int zr) {
	if (cur>k) return 0;
	if (i==n+1) return 1;
	if (dp[i][cur][last][less][zr]!=-1) return dp[i][cur][last][less][zr];
	int lim=9;
	long long ans=0;
	if (!less) lim=s[i]-'0';
	for (int c=0;c<=lim;c++) {
		int temp=cur;
		if (zr&&abs(c-last)<=d) temp++;
		ans+=f(i+1,temp,c,less|(c<s[i]-'0'),zr|(c>0));
	}
	//cout<<i<<' '<<cur<<' '<<last<<' '<<less<<' '<<zr<<' '<<ans<<endl;
	return dp[i][cur][last][less][zr]=ans;
}
long long calc(long long x) {
	s=to_string(x);
	n=s.size();
	s=' '+s;
	memset(dp,-1,sizeof(dp));
	return f(1,0,0,0,0);
} 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b>>d>>k;
    cout<<calc(b)-calc(a-1);
}