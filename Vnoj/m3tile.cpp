#include<bits/stdc++.h>
using namespace std;
int n;
long long dp[31],s[31];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    dp[0]=1;
    dp[2]=3;
    s[0]=1;
    s[2]=4;
    for (int i=4;i<=30;i++) {
    	if (i%2==1) continue;
    	dp[i]=dp[i-2]*3+s[i-4]*2;
    	s[i]=s[i-2]+dp[i];
    }
    while (cin>>n) {
    	if (n==-1) return 0;
    	cout<<dp[n]<<'\n';
    }
}