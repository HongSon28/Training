#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int>st;
    string s;
    cin>>s;
    for (int i=0;i<s.length();i++) {
        if (s[i]=='C') {
            st.push(12);
        } else if (s[i]=='H') {
            st.push(1);
        } else if (s[i]=='O') {
            st.push(16);
        } else if (s[i]=='(') {
            st.push(0);
        } else if (s[i]==')') {
            int t=0;
            while (st.top()!=0) {
                t+=st.top();
                st.pop();
            }
            st.pop();
            st.push(t);
        } else {
            int t=st.top();
            int m=(int)s[i]-48;
            st.pop();
            st.push(t*m);
        }
    }
    int res=0;
    while (!st.empty()) {
        res+=st.top();
        st.pop();
    }
    cout<<res;
}
