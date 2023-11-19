#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int res;
stack<int>st;
int main() {
    freopen("SUBP.INP","r",stdin);
    freopen("SUBP.OUT","w",stdout);
    cin>>s;
    n=s.size();
    s=' '+s;
    st.push(0);
    for (int i=1;i<=n;i++) {
        if (s[i]=='(') st.push(i);
        else {
            if (!st.empty()&&s[st.top()]=='(') {
                st.pop();
                res=max(res,i-st.top());
            } else {
                st.push(i);
            }
        }
    }
    cout<<res;
}
