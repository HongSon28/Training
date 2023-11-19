#include<bits/stdc++.h>
using namespace std;
const int N=300;
int t,n;
string s;
int dp[N+5][N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>s;
        n=s.size();
        s=' '+s;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                dp[i][j]=j-i+1;
        for (int len=2;len<=n;len++) {
            for (int i=1;i+len-1<=n;i++) {
                int j=i+len-1;
                if (s[i]==s[j]) {
                    if (len==2) dp[i][j]=1;
                    else dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                }
                for (int k=i;k<j;k++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
        cout<<dp[1][n]<<'\n';
    }
}
