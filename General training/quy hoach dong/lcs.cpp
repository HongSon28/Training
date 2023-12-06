#include<bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    int dp[n+1][m+1];
    for (int i=0;i<=m;i++) {
        dp[0][i]=0;
    }
    for (int i=0;i<=n;i++) {
        dp[i][0]=0;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i-1]==b[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string res;
    vector<int>t1,t2;
    int i=n,j=m;
    while (dp[i][j]!=0) {
        if (a[i-1]==b[j-1]) {
            res=a[i-1]+res;
            t1.push_back(i);
            t2.push_back(j);
            i--;
            j--;
        } else {
            if (dp[i-1][j]>=dp[i][j-1]) i--;
            else j--;
        }
    }
    cout<<res;
}
