#include<bits/stdc++.h>
using namespace std;
int a[10001];
int dp[10001];
int main() {
    int n;
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    dp[0]=0;
    dp[1]=abs(a[1]-a[0]);
    for (int i=2;i<n;i++) {
        dp[i]=min(dp[i-1]+abs(a[i-1]-a[i]),dp[i-2]+abs(a[i-2]-a[i]));
    }
    cout<<dp[n-1];
}
