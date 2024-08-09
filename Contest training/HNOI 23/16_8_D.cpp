#include<bits/stdc++.h>
using namespace std;
const int N=1e4,maxN=1e6;
int n;
int h[N+5];
long long res;
long long dp[N+5][N+5];
long long f[maxN+5];
long long mod=1e9+7;
void add(long long &x, long long y) {
    x+=y;
    if (x>=mod) x-=mod;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<=n;i++) {
        for (int k=1;k<i;k++) add(f[h[k]],dp[k][i]);
        for (int j=i+1;j<=n;j++) {
            if (h[i]>=h[j]) continue;
            dp[i][j]=1;
            if (h[i]-(h[j]-h[i])>0)
                add(dp[i][j],f[h[i]-(h[j]-h[i])]);
            add(res,dp[i][j]-1);
        }
        for (int k=1;k<i;k++) f[h[k]]=0;
    }
    cout<<res;
}
