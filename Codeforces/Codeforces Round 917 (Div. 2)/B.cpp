#include<bits/stdc++.h>
using namespace std;
string s;
int n,t;
bool used[26];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		memset(used,false,sizeof(used));
		long long res=0;
		cin>>n>>s;
		for (int i=0;i<(int)s.size();i++) {
			if (used[s[i]-'a']) continue;
			used[s[i]-'a']=true;
			res+=n-i;
		}
		cout<<res<<'\n';
	}
}