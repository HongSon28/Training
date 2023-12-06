#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n;
long long a[N+5],dp[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	dp[i][i]=a[i];
    }
    for (int i=n;i>=1;i--) {
    	for (int j=i+1;j<=n;j++) dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
    }
    cout<<dp[1][n];
}