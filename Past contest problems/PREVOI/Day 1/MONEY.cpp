#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n;
long long k;
long long a[N+5];
long long mod=1e9+7;
long long dp[N+5][N+5];
void add(long long &x,long long y){
    x+=y;
    if (x>=mod) x-=mod;
}
void solve12() {
    for (int i=0;i<=n;i++) dp[0][i]=1;
    for (int s=1;s<=k;s++) {
        for (int i=1;i<=n;i++) {
            dp[s][i]=dp[s][i-1];
            int cur=a[i];
            while (cur<=s) {
                add(dp[s][i],dp[s-cur][i-1]);
                cur+=a[i];
            }
        }
    }
    cout<<dp[k][n];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MONEY.INP","r",stdin);
    freopen("MONEY.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    solve12();
}
