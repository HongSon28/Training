#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="a"+s;
    bool dp[n+1][n+1];
    memset(dp,false,sizeof(dp));
    for (int i=1;i<=n;i++) {
        dp[i][i]=true;
    }
    int mx=1;
    for (int len=2;len<=n;len++) {
        for (int i=1;i<=n-len+1;i++) {
            int j=i+len-1;
            if (len==2&&s[i]==s[j])
                dp[i][j]=true;
            else {
                dp[i][j]=dp[i+1][j-1]&&s[i]==s[j];
            }
            if(dp[i][j]==true)
                mx=max(mx,len);
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<mx;
}

