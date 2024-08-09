#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
string s[N+5];
int n,l,r;
string dp[N+5][N+5];
string res="-1";
bool comp(string x,string y) {
    return x+y>y+x;
}
int main() {
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++)
        cin>>s[i];
    sort(s+1,s+n+1,comp);
    for (int i=1;i<=n;i++) {
        //cout<<s[i]<<endl;
        for (int len=r;len>=(int)s[i].size();len--) {
            dp[i][len]=dp[i-1][len];
            if (len-s[i].size()==0||!dp[i-1][len-s[i].size()].empty()) dp[i][len]=max(dp[i][len],dp[i-1][len-s[i].size()]+s[i]);
            if (len>=l&&len<=r) {
                res=max(res,dp[i][len]);
            }
            //cout<<i<<' '<<len<<' '<<dp[i][len]<<endl;
        }
        for (int len=(int)s[i].size()-1;len>=0;len--) {
            dp[i][len]=dp[i-1][len];
        }
    }
    cout<<res;
}
