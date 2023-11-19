#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
long long mod=998244353;
long long dp[N+5][N+5];
string s;
int main() {
    freopen("SEQ.INP","r",stdin);
    freopen("SEQ.OUT","w",stdout);
    cin>>s;
    int n=s.size();
    s=' '+s;
    dp[0][0]=1;
    for (int i=1;i<=n;i++) {
        if (s[i]=='(') for (int j=1;j<=N;j++) dp[i][j]=dp[i-1][j-1];
        else if (s[i]==')') for (int j=0;j<N;j++) dp[i][j]=dp[i-1][j+1];
        else for (int j=0;j<=N;j++) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%mod;
    }
    cout<<dp[n][0];
}
