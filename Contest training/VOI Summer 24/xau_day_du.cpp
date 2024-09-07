#include<bits/stdc++.h>
using namespace std;
const int N=25;
int n;
string s[N+5];
int cur[26],cnt;
int pw[26];
int res;
void rec(int k) {
	if (k==n+1) return;
	rec(k+1);
	for (auto c:s[k]) {
		if (!cur[c-'a']) cnt++;
		cur[c-'a']++;
	}
	if (cnt==26) {
		res+=pw[n-k];
		for (auto c:s[k]) {
			cur[c-'a']--;
			if (!cur[c-'a']) cnt--;
		}
		return;
	}
	rec(k+1);
	for (auto c:s[k]) {
		cur[c-'a']--;
		if (!cur[c-'a']) cnt--;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	pw[0]=1;
	for (int i=1;i<=n;i++) {
		pw[i]=pw[i-1]*2;
		string t;
		cin>>t;
		for (auto c:t) {
			if (!cur[c-'a']) {
				s[i]+=c;
				cur[c-'a']++;
			}
		}
		for (int j=0;j<26;j++) cur[j]=0;
	}
	rec(1);
	cout<<res;
}