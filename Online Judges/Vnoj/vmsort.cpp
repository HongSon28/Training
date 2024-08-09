#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int k,n;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k;
	while (k--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			string t;
			cin>>t;
			mp[t]++;
		}
	}
	cout<<mp.size();
}