#include<bits/stdc++.h>
using namespace std;
int n,k;
string m;
long long mod=1e9+7;
int a[11];
long long dp[105][15][15];
void rec(int i,int j,int carry) {
    if (i>k) return;
    cout<<i<<' '<<j<<' '<<carry<<' '<<dp[i][j][carry]<<endl;
    if (j<n) {
        for (int t=1;t<=9;t++) {
            dp[i][j+1][carry+t*a[j+1]]+=dp[i][j][carry];
            dp[i][j+1][carry+t*a[j+1]]%=mod;
            rec(i,j+1,carry+t*a[j+1]);
        }
    } else {
        if (carry%10==int(m[i]-'0'))
            for (int t=0;t<=9;t++) {
                dp[i+1][1][carry/10+t*a[1]]+=dp[i][j][carry];
                dp[i+1][1][carry/10+t*a[1]]%=mod;
                rec(i+1,1,carry/10+t*a[1]);
            }
    }
}
int main() {
    cin>>n>>m;
    k=m.size();
    k=' '+k;
    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0][0]=1;
    rec(0,0,0);
    cout<<dp[k][n][m[k]-'0'];
}
