#include<bits/stdc++.h>
using namespace std;
const int N=15000;
int dp[N+5];
int res;
int n;
string s;
stack<int>st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;
    s.resize(N*2+5);
    for (int len=1;len<=n/2;len++) {
        for (int i=1;i<=n;i++) {
            if (s[i]==s[i+len]) dp[i]=dp[i-1]+1;
            else dp[i]=0;
            dp[i]=min(dp[i],len);
            //cout<<dp[i]<<' ';
        }
        for (int i=1;i-len+1<1;i++) dp[i]=0;
        for (int start=1;start<=len;start++) {
            int i=start;
            int tp;
            while (i<=n) {
                if (st.empty()||dp[st.top()]<=dp[i]) {
                    st.push(i);
                    i+=len;
                } else {
                    tp=st.top();
                    st.pop();
                    int temp=dp[tp]*(st.empty()?i:i-st.top())/len;
                    //cout<<len<<' '<<i<<' '<<tp<<' '<<dp[tp]<<' '<<temp<<' '<<(st.empty()?i:i-st.top())/len<<endl;
                    res=max(res,temp);
                }
            }
            while (!st.empty()) {
                tp=st.top();
                st.pop();
                int temp=dp[tp]*(st.empty()?i:i-st.top())/len;
               // cout<<len<<' '<<i<<' '<<tp<<' '<<dp[tp]<<' '<<temp<<' '<<(st.empty()?i:i-st.top())/len<<endl;
                res=max(res,temp);
            }
        }
    }
    cout<<res;
}
