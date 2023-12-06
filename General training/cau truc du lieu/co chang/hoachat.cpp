#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<int>st;
    string s;
    cin>>s;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='C') st.push(12);
        else if (s[i]=='O') st.push(16);
        else if (s[i]=='H') st.push(1);
        else if (s[i]=='(') st.push(0);
        else if (s[i]==')') {
            int temp=0;
            while (st.top()!=0) {
                temp+=st.top();
                st.pop();
            }
            st.pop();
            st.push(temp);
        } else {
            int temp=st.top();
            st.pop();
            temp*=s[i]-48;
            st.push(temp);
        }
    }
    int res=0;
    while (!st.empty()) {
        res+=st.top();
        st.pop();
    }
    cout<<res;
}
