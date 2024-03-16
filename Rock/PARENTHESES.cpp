#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--){
    	bool flag=true;
    	cin>>s;
    	stack<int>st;
    	for (auto i:s) {
    		if (i=='(') st.push(1);
    		else if (i=='[') st.push(2);
    		else if (i=='{') st.push(3);
    		else if (i==')') {
    			if (!st.empty()&&st.top()==1) st.pop();
    			else {
    				flag=false;
    				break;
    			}
    		} else if (i==']') {
    			if (!st.empty()&&st.top()==2) st.pop();
    			else {
    				flag=false;
    				break;
    			}
    		} else {
    			if (!st.empty()&&st.top()==3) st.pop();
    			else {
    				flag=false;
    				break;
    			}
    		}
    	}
    	if (!flag||!st.empty()) cout<<0<<'\n';
    	else cout<<1<<'\n';
    }
}