#include<bits/stdc++.h>
using namespace std;
const int N=300;
const int M=1e6;
int n,m;
int w[N+5];
int res;
bool dp[4][M+5];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i];
    dp[0][0]=true;
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=w[i];j--) {
            if (dp[0][j-w[i]]) dp[1][j]=true;
            if (dp[1][j-w[i]]) dp[2][j]=true;
            if (dp[2][j-w[i]]) dp[3][j]=true;
        }
    }
    for (int i=1;i<=m;i++) {
        if (dp[1][i]||dp[2][i]||dp[3][i]) res++;
    }
    cout<<res;
}
