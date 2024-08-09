#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int res,cnt;
stack<int>st;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;
    st.push(0);
    for (int i=1;i<=n;i++) {
        if (s[i]=='(') st.push(i);
        else {
            if (!st.empty()&&s[st.top()]=='(') {
                st.pop();
                if (res==i-st.top()) cnt++;
                else if (res<i-st.top()) {
                	res=i-st.top();
                	cnt=1;
                }
            } else {
                st.push(i);
            }
        }
    }
    cout<<res<<' '<<cnt;
}
