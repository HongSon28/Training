#include<bits/stdc++.h>
using namespace std;
const int N=21;
int n;
int a[N+1][N+1];
long long dp[(1<<N)+1],mod=1e9+7;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=0;i<n;i++)
    	for (int j=0;j<n;j++)
    		cin>>a[i][j];
    dp[0]=1;
    for (int mask=0;mask<(1<<n);mask++)	{
    	int cnt=__builtin_popcount(mask);
    	for (int i=0;i<n;i++) {
    		if ((mask&(1<<i))||(!a[cnt][i])) continue;
    		dp[mask|(1<<i)]+=dp[mask];
    		dp[mask|(1<<i)]%=mod;
    	}
    }
	cout<<dp[(1<<n)-1];
}