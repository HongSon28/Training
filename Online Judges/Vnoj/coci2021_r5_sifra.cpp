#include<bits/stdc++.h>
using namespace std;
string s;
set<int>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	s+='a';
	int cur=0;
	for (auto i:s) {
		if (i>='a'&&i<='z') {
			if (cur!=0) st.insert(cur);
			cur=0;
		} else cur=cur*10+i-'a';
	}
	cout<<st.size();
}