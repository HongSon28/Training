#include<bits/stdc++.h>
using namespace std;
int t;
string s;
void solve() {
	for (int i=0;i<(int)s.size()-1;i++) {
		if (s[i]==s[i+1]) {
			cout<<"YES"<<'\n';
			return;
		}
	}
	cout<<"NO"<<'\n';
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>s;
    	solve();
    }
}