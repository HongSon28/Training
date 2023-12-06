#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1001], b[1001];
int dp[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>b[i];
    for (int i=0;i<=n;i++) dp[i][0]=0;
    for (int i=0;i<=m;i++) dp[0][i]=0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i]==b[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    vector<int>t,t1,t2;
    int i=n,j=m;
    while (dp[i][j]!=0) {
        if (a[i]==b[j]) {
            t.push_back(a[i]);
            t1.push_back(i);
            t2.push_back(j);
            i--;
            j--;
        } else {
            if (dp[i-1][j]>=dp[i][j-1]) i--;
            else j--;
        }
    }
    for (int i=t.size()-1;i>=0;i--) cout<<t[i]<<' ';
    cout<<endl;
    for (int i=t1.size()-1;i>=0;i--) cout<<t1[i]<<' ';
    cout<<endl;
    for (int i=t2.size()-1;i>=0;i--) cout<<t2[i]<<' ';
    cout<<endl;
}
