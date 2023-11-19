#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("TBRAC.INP","r",stdin);
    freopen("TBRAC.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        stack<char>st;
        bool flag=true;
        for (auto i:s) {
            if (i=='(') st.push(i);
            else if (i=='[') st.push(i);
            else if (i=='{') st.push(i);
            else if (i=='<') st.push(i);
            else if (i==')') {
                if (st.empty()||st.top()!='(') {
                    flag=false;
                    break;
                } else st.pop();
            } else if (i==']') {
                if (st.empty()||st.top()!='[') {
                    flag=false;
                    break;
                } else st.pop();
            } else if (i=='}') {
                if (st.empty()||st.top()!='{') {
                    flag=false;
                    break;
                } else st.pop();
            } else if (i=='>') {
                if (st.empty()||st.top()!='<') {
                    flag=false;
                    break;
                } else st.pop();
            }
        }
        if (!st.empty()) flag=false;
        if (!flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
