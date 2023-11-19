#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,q,mod=2023;
int a[N+5],dp[N+5][N+5][N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) dp[i][i][0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j++) {
            for (int step=0;step<=n;step++) {
                int temp=dp[i][j][step];
                if (temp==0) continue;
                for (int k=j+1;k<=n;k++) {
                    if (__gcd(a[j],a[k])!=1) continue;
                    dp[i][k][step+1]+=dp[i][j][step];
                    dp[i][k][step+1]%=mod;
                }
            }
        }
    }
    cin>>q;
    while (q--) {
        int ai,aj,k,u,v;
        cin>>ai>>aj>>k;
        for (int i=1;i<=n;i++) {
            if (a[i]==ai) u=i;
            if (a[i]==aj) v=i;
        }
        cout<<dp[u][v][k]<<'\n';
    }
}
