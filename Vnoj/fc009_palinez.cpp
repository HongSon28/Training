#include<bits/stdc++.h>
using namespace std;
string s;
int m,l,r;
bool check(int l,int r) {
	while (l<r) {
		if (s[l]!=s[r]) return false;
		l++;
		r--;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	s=' '+s;
	cin>>m;
	while (m--) {
		cin>>l>>r;
		if (check(l,r)) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}