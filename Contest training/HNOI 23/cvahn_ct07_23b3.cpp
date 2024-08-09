#include<bits/stdc++.h>
using namespace std;
string a,b;
string dp[1005][1005];
string getmax(string x, string y) {
    while (x[0]=='0') x.erase(0,1);
    while (y[0]=='0') y.erase(0,1);
    if (x.size()>y.size()) return x;
    if (x.size()<y.size()) return y;
    for (int i=0;i<x.size();i++) {
        if (x[i]>y[i]) return x;
        if (x[i]<y[i]) return y;
    }
    if (x.size()==0) return "0";
    return x;
}
int main() {
    freopen("NUMBER.INP","r",stdin);
    freopen("NUMBER.OUT","w",stdout);
    cin>>a>>b;
    int n=a.size(),m=b.size();
    a=' '+a;
    b=' '+b;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                dp[i][j]=getmax(dp[i-1][j-1]+a[i],dp[i][j]);
            } else dp[i][j]=getmax(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m];
}

