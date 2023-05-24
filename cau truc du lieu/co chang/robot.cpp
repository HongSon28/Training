#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<char>st;
    char x;
    while (cin>>x)st.push(x);
    while (!st.empty()) {
        cout<<st.top();
        st.pop();
    }
}
