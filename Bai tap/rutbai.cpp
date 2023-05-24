#include<bits/stdc++.h>
using namespace std;
int n;
long long a[105],dp[105][105];
int main() {
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=1;i<n-1;i++) {
        dp[i][i]=a[i-1]*a[i]*a[i+1];
    }
    for (int len=2;len<=n-2;len++) {
        for (int i=1;i<=n-len-1;i++) {
            int j=i+len-1;
            dp[i][j]=1e18;
            dp[i][j]=min(dp[i][j-1]+a[i-1]*a[j]*a[j+1],dp[i+1][j]+a[i-1]*a[i]*a[j+1]);
            for (int k=i;k<=j-2;k++) {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+2][j]+a[i-1]*a[k+1]*a[j+1]);
            }
        }
    }
    cout<<dp[1][n-2];
}
