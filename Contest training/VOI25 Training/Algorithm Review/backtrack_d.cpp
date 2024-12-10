#include<bits/stdc++.h>
using namespace std;
int n;
string s[30];
int p[27];
int power[30],res;
void rec(int i,int cur) {
	if (cur==26) {
		res+=power[n-i+1];
		return;
	}
	if (i==n+1) return;
	rec(i+1,cur);
	for (auto c:s[i]) {
		if (p[c-'a']==0) cur++;
		p[c-'a']++;
	}
	rec(i+1,cur);
	for (auto c:s[i]) p[c-'a']--;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    power[0]=1;
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
		power[i]=power[i-1]*2;
	}
	rec(1,0);
	cout<<res;
}