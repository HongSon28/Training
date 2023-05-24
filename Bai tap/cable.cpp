#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n;
    cin>>n;
    ll a[n+5],dp[n+5];
    for (int i=1;i<n;i++) cin>>a[i];
    dp[1]=0,dp[2]=a[1],dp[3]=a[1]+a[2];
    for (int i=4;i<=n;i++) {
        dp[i]=min(dp[i-1],dp[i-2])+a[i-1];
    }
    cout<<dp[n];
}
