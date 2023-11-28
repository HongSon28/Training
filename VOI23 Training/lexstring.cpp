#include<bits/stdc++.h>
using namespace std;
string s,res;
int c1[26],c2[26];
bool check(char c) {
	c1[c-'a']--;
	c2[(int)res.back()-'a']++;
	if (c2[c-'a']==0) {
		c1[c-'a']++;
		c2[(int)res.back()-'a']--;
		return false;
	}
	c2[c-'a']--;
	for (int i=0;i<26;i++) {
		if (c2[i]>c1[i]) {
			c1[c-'a']++;
			c2[(int)res.back()-'a']--;
			c2[c-'a']++;
			return false;
		}
	}
	c1[c-'a']++;
	c2[(int)res.back()-'a']--;
	c2[c-'a']++;
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	reverse(s.begin(),s.end());
	for (auto i:s) c1[(int)i-'a']++;
	for (int i=0;i<26;i++) c2[i]=c1[i]/2;
	for (int i=0;i<s.size();i++) {
		while (!res.empty()&&s[i]<res.back()&&check(s[i])) {
			c2[(int)res.back()-'a']++;
			res.pop_back();
		}
		c1[(int)s[i]-'a']--;
		if (c2[s[i]-'a']!=0) {
			c2[s[i]-'a']--;
			res+=s[i];
		}
	}
	cout<<res;
}