#include<bits/stdc++.h>
using namespace std;
string s;
int res;
bool check(string t) {
	int m=t.size()-1;
	for (int i=0;i<m;i++) {
		if (t[i]!=t[m-i]) return false;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	int n=s.size();
	s= ' '+s;
	for (int i=1;i<=n;i++) {
		for (int len=2;i+len-1<=n;len++) {
			res+=check(s.substr(i,len));
		}
	}
	cout<<res;
}