#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n;
long long a[N+5];
long long dp[N+5];
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1],dp[2]=a[2],dp[3]=a[3],dp[4]=a[4];
    for (int i=5;i<=n;i++) dp[i]=min({dp[i-1],dp[i-2],dp[i-3],dp[i-4]})+a[i];
    cout<<min({dp[n],dp[n-1],dp[n-2],dp[n-3]});
}
