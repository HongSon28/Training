#include<iostream>
using namespace std;
const long long mod=2111992;
int main() {
    long long n,k;
    cin>>n>k;
    long long dp[n+1];
    for (long long i=1;i<=k+1;i++) dp[i]=i+1;
    for (long long i=k+2;i<=n;i++) {
        dp[i]=(dp[i-1]+dp[i-k-1])%mod
    }
    cout<dp[n];
}
