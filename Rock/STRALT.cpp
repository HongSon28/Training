#include<bits/stdc++.h>
using namespace std;
string s;
int n;
stack<string>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    for (int i=0;i<(int)s.size();i++) {
    	if (s[i]>='0'&&s[i]<='9') {
    		if (!st.empty()&&st.top().back()>='0'&&st.top().back()<='9') st.top()+=s[i];
    		else {
    			string t;
    			t+=s[i];
    			st.push(t);
    		}
    	} else if (s[i]==')') {
    		string x=st.top();
    		st.pop();
    		st.pop();
    		int cnt=stoi(st.top());
    		st.pop();
    		string y;
    		while (cnt--) y+=x;
    		while (!st.empty()&&st.top().back()>='a'&&st.top().back()<='z') {
    			y=st.top()+y;
    			st.pop();
    		}
    		st.push(y);
    	} else if (s[i]==']') {
    		string x=st.top();
    		st.pop();
    		st.pop();
    		if (s[i-1]=='*') {
    			string y=x;
    			y.pop_back();
    			reverse(y.begin(),y.end());
    			x+=y;
    		} else {
    			string y=x;
    			reverse(y.begin(),y.end());
    			x+=y;
    		}
    		while (!st.empty()&&st.top().back()>='a'&&st.top().back()<='z') {
    			x=st.top()+x;
    			st.pop();
    		}
    		st.push(x);
    	} else if (s[i]=='('||s[i]=='[') {
    		n++;
    		string t;
    		t+=s[i];
    		st.push(t);
    	} else if (s[i]>='a'&&s[i]<='z') {
    		if (!st.empty()&&st.top().back()>='a'&&st.top().back()<='z') st.top()+=s[i];
    		else{
    			string t;
    			t+=s[i];
    			st.push(t);
    		}
    	}
    }
    cout<<n<<'\n'<<st.top();
}