#include<bits/stdc++.h>
using namespace std;
long long a,b;
int s;
long long dp[17][2][136];
string st;
int n;
long long f(int i,bool less,int sum) {
	if (i==n) return sum==s;
	if (dp[i][less][sum]!=-1) return dp[i][less][sum];
	int t=min(s-sum,9);
	long long cur=0;
	if (!less) t=min(t,st[i]-'0');
	for (int c=0;c<=t;c++) {
		if (c<st[i]-'0') cur+=f(i+1,less|1,sum+c);
		else cur+=f(i+1,less,sum+c);
	}
	//cout<<i<<' '<<less<<' '<<sum<<' '<<cur<<endl;
	return dp[i][less][sum]=cur;
}
long long get(long long x) {
	memset(dp,-1,sizeof(dp));
	st=to_string(x);
	n=st.size();
	return f(0,0,0);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>a>>b>>s;
    long long k=get(a-1);
    cout<<get(b)-k<<'\n';
    long long res,lo=a,hi=b;
    while (lo<=hi) {
    	long long mid=(lo+hi)/2;
    	//cout<<lo<<' '<<hi<<' '<<mid<<' '<<get(mid)<<endl;
    	if (get(mid)>=k+1) {
    		res=mid;
    		hi=mid-1;
    	} else lo=mid+1;
    }
    cout<<res;
}