#include<bits/stdc++.h>
using namespace std;
long long x,k;
string s;
int n;
long long dp[20][2][10][2];
long long f(int i,int les,int last,int nz) {
	if (i==n) return 1;
	if (dp[i][les][last][nz]!=-1) return dp[i][les][last][nz];
	int lim=9;
	long long ans=0;
	if (!les) lim=(int)s[i]-'0';
	for (int c=0;c<=lim;c++) {
		if (nz&&abs(c-last)>1) continue;
		ans+=f(i+1,les|(c<(int)s[i]-'0'),c,nz|(c!=0));
	}
	//cout<<i<<' '<<les<<' '<<last<<' '<<ans<<endl;
	return dp[i][les][last][nz]=ans;
}
long long get(long long t) {
	s=to_string(t);
	n=s.size();
	memset(dp,-1,sizeof(dp));
	return f(0,0,0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>x;
    long long p=get(x)+k;
    long long lo=x+1,hi=1e18,res;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (get(mid)>=p) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
    cout<<res;
}