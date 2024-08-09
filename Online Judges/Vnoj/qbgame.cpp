#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[8][n];
    for (int i=0;i<8;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    long long dp[8][n];
    for (int i=0;i<n;i++) {
        if (a[0][i]>0) dp[0][i]=a[0][i];
        else dp[0][i]=0;
    }
    for (int i=1;i<8;i++) {
        for (int j=0;j<n;j++) {
            long long t=INT_MIN;
            for (int k=0;k<n;k++) {
                if (k!=j) t=max(t,dp[i-1][k]);
            }
            dp[i][j]=t;
            if (a[i][j]>0) dp[i][j]+=a[i][j];
        }
    }
    long long res=INT_MIN;
    for (int i=0;i<n;i++) {
        res=max(res,dp[7][i]);
    }
    cout<<res;
}
