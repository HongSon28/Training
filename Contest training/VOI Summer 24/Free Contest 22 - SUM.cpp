#include<bits/stdc++.h>
using namespace std;
int n;
long long a,b,s;
string st;
long long dp[16][2][136];
long long f(int i,int les,int sum) {
	if (i==n) return sum==s;
	if (sum>s) return 0;
	if (dp[i][les][sum]!=-1) return dp[i][les][sum];
	int l=9;
	if (!les) l=(int)st[i]-'0';
	long long ans=0;
	for (int t=0;t<=l;t++) {
		ans+=f(i+1,les|(t<(int)st[i]-'0'),sum+t);
	} 
	return dp[i][les][sum]=ans;
}
long long get(long long x) {
	st=to_string(x);
	n=st.size();
	memset(dp,-1,sizeof(dp));
	return f(0,0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b>>s;
    long long k=get(a-1);
    cout<<get(b)-k<<'\n';
    long long lo=a,hi=b,ans;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	if (get(mid)>k) {
    		ans=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
    cout<<ans;
}