#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long mod=1e9+7,dp[N+5],res;
int a[N+5];
int main() {
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0]=1;
    long long sum=1;
    for (int i=1;i<=n;i++) {
        long long temp=((sum-dp[a[i]])%mod+mod)%mod;
        sum+=temp;
        sum%=mod;
        dp[a[i]]+=temp;
        dp[a[i]]%=mod;
    }
    for (int i=1;i<=N;i++) {
        res+=dp[i];
        res%=mod;
    }
    cout<<res;
}
