#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,m;
int d[N+5],sum[N+5];
int dp[N+5];
int getsum(int l,int r) {
    return sum[r]-sum[l-1];
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>d[i];
        sum[i]=sum[i-1]+d[i];
    }
    for (int i=1;i<=n;i++) {
        dp[i]=dp[i-1];
        for (int k=1;k*2<=i;k++) {
            dp[i]=max(dp[i-k*2]+getsum(i-k*2+1,i-k),dp[i]);
        }
    }
    cout<<dp[n];
}
