#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
long long k,m,n;
long long dp[N+5][N+5];
long long mod=1e9+7;
long long res;
int main() {
    freopen("SEQK.INP","r",stdin);
    freopen("SEQK.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>k>>m>>n;
    for (int i=1;i<m;i++)dp[1][i]=1;
    for (int i=2;i<=n;i++) {
        for (int j=1;j<m;j++) {
            if (j+k<m) {
                dp[i][j]+=dp[i-1][j+k];
                dp[i][j]%=mod;
            }
            if (j-k>0) {
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=mod;
            }
        }
    }
    for (int i=1;i<m;i++) {
        res+=dp[n][i];
        res%=mod;
    }
    cout<<res;
}
