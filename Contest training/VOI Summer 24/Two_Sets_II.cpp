#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,sum,mod=1e9+7;
int dp[N+5];
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    sum=(n+1)*n/2;
    if (sum%2) {
    	cout<<0;
    	return 0;
    }
    sum/=2;
    dp[0]=1;
    for (int i=1;i<=n;i++) {
    	for (int s=sum;s>=i;s--) add(dp[s],dp[s-i]);
    } 
    cout<<(long long)dp[sum]*500000004%mod;
}