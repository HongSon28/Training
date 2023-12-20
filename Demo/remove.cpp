#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	while (cin>>s) {
		if (s[0]>='0'&&s[0]<='9') continue;
		cout<<s<<' ';
	}
}