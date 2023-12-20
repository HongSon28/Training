#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
stack<char>st;
queue<char>temp;
int main() {
	freopen("DECODE.INP","r",stdin);
	freopen("DECODE.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    for (auto i:s) {
    	if (i>='A'&&i<='Z') {
    		st.push(i);
    	} else if (i=='(') {
    		st.push(i);
    	} else {
    		while (st.top()!='(') {
    			temp.push(st.top());
    			st.pop();
    		}
    		st.pop();
    		while(!temp.empty()) {
    			st.push(temp.front());
    			temp.pop();
    		}
    	}
    }	
    string res;
    while (!st.empty()) {
    	res+=st.top();
    	st.pop();
    }
    reverse(res.begin(),res.end());
    cout<<res;
}