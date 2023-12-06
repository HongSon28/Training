#include<bits/stdc++.h>
using namespace std;
int d[101];
int dp[101][101];
int main() {
    int n;
    cin>>n;
    for (int i=0;i<=n;i++) cin>>d[i];
    for (int a=1;a<n;a++) {
        for (int b=0,c=a+b;c<n;b++,c++) {
            int mn=INT_MAX;
            for (int e=b;e<c;e++) {
                mn=min(mn,dp[b][e]+dp[e+1][c]+d[b]*d[e+1]*d[c+1]);
            }
            dp[b][c]=mn;
        }
    }
    cout<<dp[0][n-1];
}
