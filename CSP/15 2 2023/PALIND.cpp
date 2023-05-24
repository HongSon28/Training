#include <bits/stdc++.h>
using namespace std;
bool dp[10001][10001];
int main(){
    freopen("PALIND.INP","r",stdin);
    freopen("PALIND.OUT","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    s="a"+s;
    memset(dp,false,sizeof(dp));
    for (int i=1;i<=n;i++) {
        dp[i][i]=true;
    }
    int mx=1;
    string res;
    for (int i=1;i<=n;i++) {
        if (s[i]!='0'){
            res+=s[i];
            break;
        }
    }
    for (int len=2;len<=n;len++) {
        for (int i=1;i<=n-len+1;i++) {
            int j=i+len-1;
            if (len==2&&s[i]==s[j])
                dp[i][j]=true;
            else {
                dp[i][j]=dp[i+1][j-1]&&s[i]==s[j];
            }
            if(dp[i][j]==true) {
                if (mx<len&&s[i]!='0') {
                    mx=len;
                    res=s.substr(i,len);
                }
            }
        }
    }
    cout<<mx<<endl<<res;
}

