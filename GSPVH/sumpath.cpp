#include<bits/stdc++.h>
using namespace std;
const int N=2207;
int m,n;
long long a[N+5][N+5];
char c[N+5][N+5];
long long dp[N+5][N+5];
int mod=998244353;
long long res;
int main() {
	freopen("sumpath.inp","r",stdin);
	freopen("sumpath.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) {
    		cin>>c[i][j];
    		a[i][j]=c[i][j]-'0';
    	}
    }
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) {
    		if (i==1&&j==1) dp[i][j]=1;
    		else dp[i][j]=(dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1])%mod;
    	}
    }
    for (int i=1;i<=m;i++) {
    	for (int j=1;j<=n;j++) {
    		res+=dp[m-i+1][n-j+1]*dp[i][j]%mod*a[i][j]%mod;
    		res%=mod;
    	}
    }
    cout<<res;
}