#include<bits/stdc++.h>
using namespace std;
const int N=4e3;
int n;
long long dp[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    dp[0]=1;
    for (int i=1;i<=n;i++) {
    	for (int s=n;s>=i;s--) dp[s]+=dp[s-i];
    }
    cout<<dp[n]-1;
}