#include<bits/stdc++.h>
using namespace std;
int n;
string s;
stack<char>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>s;
	for (auto i:s) {
		if (i=='(') {
			st.push(i);
			cout<<i;
		} else {
			if (st.empty()) {
				cout<<"()";
			} else {
				st.pop();
				cout<<i;
			}
		}
	}
	while (!st.empty()) {
		st.pop();
		cout<<')';
	}
}