#include<bits/stdc++.h>
using namespace std;
const int N=500;
long long a[N+5],res;
long long dp[N+5][N+5][N+5];
int n,k,cnt;
void solve1() {
    for (int i=1;i<=n-k;i++) {
        res+=max(a[i]-a[i-1],0ll);
    }
    cout<<res;
}
int main() {
    //freopen("RESEARCH.INP","r",stdin);
    //freopen("RESEARCH.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (k==0) {
        solve1();
        return 0;
    }
    for (int i=1;i<=n;i++)
        if (a[i]>=a[i-1]) cnt++;
    if (cnt==n) {
        solve1();
        return 0;
    }
}
