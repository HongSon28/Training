#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int inf=1e9;
int n;
int dp[N+5];
int main() {
    cin>>n;
    for (int i=0;i<=N;i++) dp[i]=inf;
    dp[0]=0;
    for (int i=0;i<=n;i++) {
        for (auto c:to_string(i)) dp[i]=min(dp[i],dp[i-(c-'0')]+1);
    }
    cout<<dp[n];
}
