#include<bits/stdc++.h>
#include "egg.h"
using namespace std;
const int N=1e3;
long long dp[N+5][N+5],inf=1e9;
int opt[N+5][N+5];
int state[N+5];
long long f(int e,int d) {
	if (e==0) return inf;
	if (d==0) return 0;
	if (e==1) {
		opt[e][d]=1;
		return d;
	}
	if (dp[e][d]!=-1) return dp[e][d];
	dp[e][d]=inf;
	for (int i=1;i<=d;i++) {
		long long mx=max(f(e-1,i-1),f(e,d-i));
		if (dp[e][d]>mx+1) {
			dp[e][d]=mx+1;
			opt[e][d]=i;
		}
	}
	return dp[e][d];
}
/*
bool drop(int t) {
    bool k;
    cout<<t<<endl;
    cin>>k;
    return k;
}
*/
int solve(int e,int n) {
	int lo=1,hi=n;
	int mx=n;
	memset(dp,-1,sizeof(dp));
	while (true) {
		f(e,n);
		int cur=lo+opt[e][n]-1;
		//cout<<"CHOOSE "<<opt[e][n]<<endl;
		bool t=drop(cur);
		if (!t) {
			state[cur]=1;
			e--;
			hi=cur-1;
			if (cur==1||state[cur-1]==2) return cur-1;
		} else {
			state[cur]=2;
			lo=cur+1;
			if (cur==mx||state[cur+1]==1) return cur;
		}
        n=hi-lo+1;
		//cout<<"MOVE "<<cur<<' '<<t<<' '<<e<<' '<<n<<' '<<lo<<' '<<hi<<endl;
	}
}
/*
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout<<solve(2,100)<<" =ANS";
}
*/
