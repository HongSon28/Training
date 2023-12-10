#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int n;
string s;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	while (n--) {
		cin>>s;
		mp[s]++;
	}
	for (auto i=mp.begin();i!=mp.end();i++) {
		if (i->second&1) {
			cout<<i->first;
			return 0;
		}
	}
	cout<<-1;
}