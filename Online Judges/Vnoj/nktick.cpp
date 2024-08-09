#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int t[n+1];
    int r[n];
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<n;i++) cin>>r[i];
    int dp[n+1];
    dp[0]=0;
    dp[1]=t[1];
    for (int i=2;i<=n;i++) {
        dp[i]=min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
    }
    cout<<dp[n];
}
