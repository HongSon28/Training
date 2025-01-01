#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long a[N+5];
namespace sub1{
    long long inf=1e18,res=inf;
    long long calc(int mask) {
        vector<long long>cur;
        for (int i=0;i<n;i++) {
            if (mask>>i&1) cur.push_back(a[i+1]);
        }
        long long s=0;
        for (int i=1;i<(int)cur.size();i+=2) s+=cur[i]-cur[i-1];
        return s;
    }
    void solve() {
        for (int mask=0;mask<(1<<n);mask++) {
            if (__builtin_popcount(mask)==k*2) res=min(res,calc(mask));
        }
        cout<<res;
    }
}
namespace sub2{
    const int M=2000;
    long long dp[M+5][M+5],inf=1e18;
    void solve() {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=k;j++) {
                dp[i][j]=inf;
                if (j*2>i) break;
                dp[i][j]=min(dp[i][j],dp[i-1][j]);
                dp[i][j]=min(dp[i][j],dp[i-2][j-1]+a[i]-a[i-1]);
            }
        }
        cout<<dp[n][k];
    }
}
int main() {
    freopen("DAN.INP","r",stdin);
    freopen("DAN.ANS","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    sub2::solve();
}

