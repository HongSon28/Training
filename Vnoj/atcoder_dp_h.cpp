#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3;
ll mod=1000000007;
ll dp[N+5][N+5];
char c[N+5][N+5];
int h,w;
int main() {
    cin>>h>>w;
    for (int i=1;i<=h;i++)
        for (int j=1;j<=w;j++)
            cin>>c[i][j];
    dp[1][1]=1;
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            if (i==1&&j==1) continue;
            if (c[i][j]=='.') {
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[h][w];
}
