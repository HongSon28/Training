#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t[N+5],p[N+5],dp[N+5];
int n;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>t[i];
    for (int i=1;i<n;i++) cin>>p[i];
    dp[1]=t[1];
    for (int i=2;i<=n;i++) dp[i]=min(dp[i-1]+t[i],dp[i-2]+p[i-1]);
    cout<<dp[n];
}
