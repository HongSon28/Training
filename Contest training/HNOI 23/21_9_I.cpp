#include<bits/stdc++.h>
using namespace std;
const int N=100,maxN=5000;
int m,k;
int a[N+5];
int sum;
long long dp[N+5][N/2+5][maxN+5],mod=1e9+7;
long long fac=1;
void solve1() {
    dp[0][0][0]=1;
    for (int i=1;i<=m;i++) {
        for (int j=0;j<=i;j++) {
            for (int s=0;s<=sum/2;s++) {
                dp[i][j][s]=dp[i-1][j][s];
                if (s>=a[i]&&j!=0) {
                    dp[i][j][s]+=dp[i-1][j-1][s-a[i]];
                    dp[i][j][s]%=mod;
                }
                //cout<<i<<' '<<j<<' '<<s<<' '<<dp[i][j][s]<<endl;
            }
        }
    }
    cout<<(((dp[m][m/2][sum/2]*fac)%mod)*fac)%mod;
}
void solve2() {
    for (int i=1;i<=m;i++) {

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>k;
    for (int i=2;i<=m/2;i++) {
        fac*=i;
        fac%=mod;
    }
    for (int i=1;i<=m;i++) {
        long long t;
        cin>>t;
        while (t>0) {
            a[i]+=t%10;
            t/=10;
        }
        sum+=a[i];
    }
    if (m%2==0) solve1();
    else solve2();
}
