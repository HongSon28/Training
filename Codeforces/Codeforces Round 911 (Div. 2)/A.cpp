#include<bits/stdc++.h>
using namespace std;
int t,n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		int cnt=0;
		bool flag=false;
		cin>>n>>s;
		for (int i=0;i<(int)s.size()-2;i++) {
			if (s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.') {
				flag=true;
				break;
			} if (s[i]=='.') cnt++;
		}
		if (s[s.size()-2]=='.') cnt++;
		if (s[s.size()-1]=='.') cnt++;
		if (flag) cout<<2<<'\n';
		else cout<<cnt<<'\n';
	}
}